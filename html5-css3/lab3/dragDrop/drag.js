let leftContainer = document.getElementById("left");
let rightContainer = document.getElementById("right");
let images = document.images;
let reset = document.getElementById('refresh');


// images >> dragstart, dragend
// right section >> dragleave
// left section >> dragenter, dragover, drop

let correctDragDrop = false;

for (let i = 0; i < images.length; i++) {
    images[i].addEventListener("dragstart", e => {
        e.dataTransfer.setData('botato', e.target.outerHTML);
        console.log('drag ends');
        console.dir( e.target)
        correctDragDrop = false;
    })
    images[i].addEventListener("dragend", e => {
        console.log('drag ends');
        if (correctDragDrop) e.target.style.display = "none";
    })
}

rightContainer.addEventListener('dragleave', e => e.preventDefault());
leftContainer.addEventListener('dragenter', e => e.preventDefault());
leftContainer.addEventListener('dragover', e => e.preventDefault());
leftContainer.addEventListener('drop', e => {
     e.preventDefault();
     leftContainer.innerHTML += e.dataTransfer.getData("botato");
     correctDragDrop = true;
});

reset.addEventListener('click', e=> {
    location.reload();
    
})