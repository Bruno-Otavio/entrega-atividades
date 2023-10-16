// Exercício 1

function operation() {
  let number1 = Number(document.querySelector("#number1").value);
  let number2 = Number(document.querySelector("#number2").value);
  let number3 = Number(document.querySelector("#number3").value);

  document.querySelector(
    "#resultEx1"
  ).innerHTML = `(${number1} + ${number2}) / ${number3} = ${
    (number1 + number2) / number3
  }`;
}

// Exercício 2

function calculateKmPerHour() {
  let speed = Number(document.querySelector("#speed").value);
  let distance = Number(document.querySelector("#distance").value);

  let result = speed / distance;

  document.querySelector("#resultEx2").innerHTML = `${result}km/h`;
}

// Exercício 3

function reajust() {
  let nome = document.querySelector("#name").value;
  let salary = Number(document.querySelector("#salary").value);
  let index = Number(document.querySelector("#index").value);

  let result = salary + (salary * index) / 100;

  document.querySelector(
    "#resultEx3"
  ).innerHTML = `Nome: ${nome} - Reajuste: R$${result}`;
}

// Exercício 4

function calculatePoints() {
  let club = document.querySelector("#club").value;
  let victories = Number(document.querySelector("#victories").value);
  let draws = Number(document.querySelector("#draws").value);

  let points = victories * 3 + draws;

  document.querySelector(
    "#resultEx4"
  ).innerHTML = `Clube de Futebol: ${club} - Pontos Totais: ${points}`;
}

// Exercício 5

function pastPosNumber() {
  let number = Number(document.querySelector("#number").value);

  document.querySelector("#resultEx5").innerHTML = `${number} - 1 = ${
    number - 1
  } | ${number} + 1 = ${number + 1}`;
}

// Exercício 6

function planeHours() {
  const speed = 900;

  let distance = document.querySelector("#travel-distance").value;

  let hours = distance / speed;

  document.querySelector("#resultEx6").innerHTML = `Horas em voo: ${hours}`;
}

// Exercício 7

function travelAmount() {
  const cargoPerTruck = 18; // Toneladas
  const production = 250; // Toneladas

  let trucks = Number(document.querySelector("#trucks").value);
  let alqueiros = Number(document.querySelector("#alqueiro").value);

  let travelAmount = (alqueiros * production) / (trucks * cargoPerTruck);

  document.querySelector(
    "#resultEx7"
  ).innerHTML = `Serão necessárias ${travelAmount} viagens`;
}

// Exercício 8

function cilinderCalculate() {
  const PI = 3.14;

  let raio = Number(document.querySelector("#raio").value);
  let height = Number(document.querySelector("#height").value);

  let area = 2 * PI * (raio * raio) + 2 * PI * raio * height;
  let volume = PI * (raio * raio) * height;

  document.querySelector(
    "#resultEx8"
  ).innerHTML = `Área do Cilindro: ${area} | Volume do Cilindro ${volume}`;
}

// Exercício 9

function priceChanger() {
  let mercadoria = document.querySelector("#mercadoria").value;
  let price = Number(document.querySelector("#price").value);

  let newPrice = price + (price * 5) / 100;

  document.querySelector(
    "#resultEx9"
  ).innerHTML = `Valor de ${mercadoria} após o reajuste de 5%: R$${newPrice}`;
}

// Exercício 10

function participation() {
  let city = document.querySelector("#city").value;
  let electors = Number(document.querySelector("#electors").value);
  let votes = Number(document.querySelector("#votes").value);

  let votosPercentage = (votes * 100) / electors;

  document.querySelector(
    "#resultEx10"
  ).innerHTML = `A cidade de ${city} teve um total de ${votosPercentage}% de participantes`;
}
