const statuse = document.getElementById('status');
const frame = document.getElementById('map-frame');

function getLocation() {
    statuse.innerHTML = "Locating...";

    // 1. Ask the browser for coordinates
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showPosition, showError);
    } else {
        statuse.innerHTML = "Geolocation is not supported by this browser.";
    }
}

function showPosition(position) {
    const lat = position.coords.latitude;
    const lon = position.coords.longitude;

    statuse.innerHTML = `Latitude: ${lat} <br> Longitude: ${lon}`;

    const offset = 0.01;
    frame.src = `https://www.openstreetmap.org/export/embed.html?bbox=${lon - offset},${lat - offset},${lon + offset},${lat + offset}&layer=mapnik&marker=${lat},${lon}`;
}

function showError(error) {
    statuse.innerHTML = "Error: " + error.message;
}