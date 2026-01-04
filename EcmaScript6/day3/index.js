let options = document.getElementById("products");
let container = document.getElementById("container");

let products = fetch("https://fakestoreapi.com/products").then(
    res => res.json()
).then(data => {
    let tmp = "";
    data.forEach(p => {
        tmp += `
            <option value="${p.id}">
                ${p.title}
            </option>
        `
    });
    options.innerHTML = tmp;
    options.disabled = false;
});


options.addEventListener('change', e => {
    let productDetails = fetch(`https://fakestoreapi.com/products/${e.target.value}`).then(
        res => res.json()).then(data => {
            container.innerHTML = `
            <div class="right">
                <img src="${data.image}" alt="${data.title}">
            </div>
            <div class="left">
                <p class="category">${data.category}</p>
                <h1 class="title">${data.title}</h1>
                <p class="rating">${data.rating.rate} Stars <span class="count">(${data.rating.count} reviews</span>)</p>
                <h2 class="price">${data.price} $</h2>
                <p class="description">${data.description}</p>
                <button class="addToCart"><span>&#128722;</span>Add To Cart</button>
            </div>
            `
        });

});