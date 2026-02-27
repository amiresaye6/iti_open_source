const express = require('express');
const schemas = require('../schemas/donation');
const donationsController = require('../controllers/donations');
const validate = require('../middlewares/validator');

const router = express.Router();


router.post("/", validate(schemas.donateSchema), donationsController.createDonation);

router.post("/webhook", donationsController.webhook)


module.exports = router;
