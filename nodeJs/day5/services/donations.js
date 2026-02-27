const Donation = require('../modules/donations');
const axios = require('axios');
const crypto = require('crypto');
const querystring = require('node:querystring');
const _ = require('underscore');

const httpClient = axios.create({
    baseURL: process.env.KASHIER_URL,
    headers: {
        'Content-Type': 'application/json',
        'Authorization': process.env.KASHIER_SECRET_KEY,
        'api-key': process.env.KASHIER_API_KEY,
    }
});


const createPaymentSessionFromProvider = async (amount) => {
    const order = `DONATION-${Date.now()}`;
    let response

    try {
        response = await httpClient.post('/v3/payment/sessions', {
            paymentType: "credit",
            amount: amount.toString(),
            currency: "EGP",
            order: order,
            display: "en",
            allowedMethods: "card,wallet",
            // TODO: change the redirect url
            merchantRedirect: "https://example.com/redirect",
            redirectMethod: "post",
            failureRedirect: false,
            iframeBackgroundColor: "#FFFFFF",
            merchantId: process.env.KASHIER_MERCHANT_ID,
            brandColor: "#5020FF",
            defaultMethod: "card",
            description: `Payment for order ${order}`,
            manualCapture: false,
            saveCard: "none",
            interactionSource: "ECOMMERCE",
            enable3DS: true,
            serverWebhook: "https://ostracizable-jacqualine-blurredly.ngrok-free.dev/donation/webhook",
            notes: "please support our blog"
        });
    } catch (err) {
        console.log("error from the trycatch   ", err.stack)
    }
    console.log("res  is ", response);
    return response?.data;
};

const createDonation = async (donationData) => {
    const donation = await Donation.create(donationData);
    return donation;
};

const handelWebhook = (data, signatureHeader) => {
    data.signatureKeys.sort();
    const objectSignaturePayload = _.pick(data, data.signatureKeys);

    // Use the built-in querystring.stringify instead
    const signaturePayload = querystring.stringify(objectSignaturePayload);

    const signature = crypto
        .createHmac('sha256', process.env.KASHIER_API_KEY)
        .update(signaturePayload)
        .digest('hex');

    if (signatureHeader === signature) {
        return true;
    } else {
        return false;
    }
};

const updateDonationStatus = async (body) => {
    const { data, event } = body;
    const donation = await Donation.findOne({ orderId: data.merchantOrderId });
    if (!donation) {
        throw new APIError("donation not found", 404);
    };
    const updateQuery = {
        $set: {
            status: data.status === "SUCCESS" ? "PAID" : "FAILED",
            webhookData: body,
        }
    };
    await Donation.updateOne({ _id: donation._id }, updateQuery);
};

module.exports = {
    createPaymentSessionFromProvider,
    createDonation,
    handelWebhook,
    updateDonationStatus
};