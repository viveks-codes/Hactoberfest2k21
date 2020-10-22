let computerImage = document.createElement('img');
let userImage = document.createElement('img');
let user = document.getElementById('user');
let computer = document.getElementById('COMPUTER');
const imageList = document.getElementsByClassName('selectimg');
const landingPage = document.getElementById('landingpage');
const gamePage = document.getElementById('gamepage');
const images = document.getElementById('images');
let userScore = 0;
let computerScore = 0;
let loader = true;


let imageObject = [
    {
        imgSrc : "https://static.thenounproject.com/png/477918-200.png",
        imgTitle : "Rock"
    },
    {
        imgSrc : "https://static.thenounproject.com/png/477922-200.png",
        imgTitle : "Paper"
    },
    {
        imgSrc : "https://static.thenounproject.com/png/477919-200.png",
        imgTitle : "Scissor"
    }
]

function getImage(image) {
    landingPage.classList.add('nextpage');
    gamePage.classList.add('show');
    images.classList.add('images-next-page');
    [...imageList].forEach(element => {
        element.classList.add('img-next-page')
    });
    displayUserImage(image);
    displayComputerImage();
}

function displayUserImage(image){
    userImage.src = image.src;
    userImage.title = image.title;
    user.appendChild(userImage);
}

function displayComputerImage() {
    let randomNumber = Math.floor(Math.random()*3); 
    if (loader === true) {
        loading();
    }
    if (loader === false) {
        computerImage.src = imageObject[randomNumber].imgSrc;
        computerImage.title = imageObject[randomNumber].imgTitle;
        computerImage.classList.add('computer-img');
        computer.appendChild(computerImage);
        loader = true;
        compareImage();
    }
}

function compareImage() {
    let score = document.getElementById('score');
    if(userImage.title === computerImage.title){
        userScore += 1;
        computerScore += 1;
    } else if ((userImage.title === 'Rock' && computerImage.title === 'Paper') || (userImage.title === 'Paper' && computerImage.title === 'Scissor') || (userImage.title === 'Scissor' && computerImage.title === 'Rock')) {
        computerScore += 1;
    } else {
        userScore += 1;
    }
    score.textContent = `${userScore} - ${computerScore}`
}

function sleep(ms){
    return new Promise((resolve) => setTimeout(resolve, ms));
}

async function loading(){
    for (let i = 0; i<2; i++){
        for (let j = 0; j<3;j++){
            computerImage.src = imageObject[j].imgSrc;
            computerImage.title = imageObject[j].imgTitle;
            computerImage.classList.add('computer-img');
            await sleep(100);
            computer.appendChild(computerImage);
        }
    }
    loader = false;
    displayComputerImage();
}



[...imageList].forEach(image => {
    image.addEventListener('click', () => {
        getImage(image);
    })
})