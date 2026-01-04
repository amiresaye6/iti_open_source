const sideBar = document.querySelector('.sidebar');
let currentIndex = 0;

let videos = [
    "../assets/video/test.mp4",
    
    "../assets/video/test.mp4",
    "../assets/video/video2.mp4",
    "../assets/video/test.mp4",
    "../assets/video/test.mp4",
    "../assets/video/video2.mp4",
    "../assets/video/test.mp4",
    "../assets/video/video2.mp4"
]

let vidx = 0;
let nameFieldIndex = videos[0].split("/").length - 1;

videos.forEach(v => {
    let vid = `<button class="button" onclick="showVideo('${v}', ${vidx++})">${v.split('/')[nameFieldIndex].split('.')[0]}</button>`;
    sideBar.innerHTML += vid;
    console.dir(sideBar)
})
const buttons = document.querySelectorAll('.button');



function showVideo(vSrc, idx) {
    console.log('clicked', vSrc);

    const videoPlayer = document.getElementById('videoPlayer');
    const videoSource = document.getElementById('videoSource');
    buttons.forEach(btn => {
        btn.classList.remove('active')
    })
    buttons[idx].classList.add('active')
    videoSource.src = vSrc;
    videoPlayer.load();
}

function updateActiveButton() {
    buttons.forEach((button, index) => {
        if (index === currentIndex) {
            button.classList.add('active');
        } else {
            button.classList.remove('active');
        }
    });
}

document.addEventListener('keydown', (event) => {
    if (event.key === 'ArrowDown') {
        currentIndex = (currentIndex + 1) % buttons.length;
        updateActiveButton();
    } else if (event.key === 'ArrowUp') {
        currentIndex = (currentIndex - 1 + buttons.length) % buttons.length;
        updateActiveButton();
    } else if (event.key === 'Enter') {
        buttons[currentIndex].click();
    }
});

const videoElement = document.getElementById('videoPlayer');
videoElement.addEventListener('click', () => {
    if (videoElement.paused) {
        videoElement.play();
    } else {
        videoElement.pause();
    }
});

videoElement.addEventListener('dblclick', () => {
    if (videoElement.requestFullscreen) {
        videoElement.requestFullscreen();
    }
});

updateActiveButton();