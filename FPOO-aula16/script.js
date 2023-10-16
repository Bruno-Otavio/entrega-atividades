const object = {};

object.nome = "Bola";
object.preco = 39.9;
object.quantidade = 10;

object.total = function () {
  return object.preco * object.quantidade;
};

object.showHTML = () => {
  let string = `
    <label>Nome: </label><label>${object.nome}</label>
    <label>Preço: </label><label>R$${object.preco.toFixed(2)}</label>
    <label>Quantidade: </label><label>${object.quantidade}</label>
    <label>Total: </label><label>R$${object.total().toFixed(2)}</label>`;

  return string;
};

const object2 = {
  nome: "Monitor",
  preco: 749.9,
  quantidade: 3,

  total() {
    return this.preco * this.quantidade;
  },

  showHTML() {
    let string = `
      <label>Nome: </label><label>${this.nome}</label>
      <label>Preço: </label><label>R$${this.preco.toFixed(2)}</label>
      <label>Quantidade: </label><label>${this.quantidade}</label>
      <label>Total: </label><label>R$${this.total().toFixed(2)}</label>`;

    return string;
  },
};

console.log(object2);

const object3 = {
  nome: "Cadeira",
  preco: 110.9,
  quantidade: 3,

  total() {
    return this.preco * this.quantidade;
  },

  showHTML() {
    let string = `
      <label>Nome: </label><label>${this.nome}</label>
      <label>Preço: </label><label>R$${this.preco.toFixed(2)}</label>
      <label>Quantidade: </label><label>${this.quantidade}</label>
      <label>Total: </label><label>R$${this.total().toFixed(2)}</label>`;

    return string;
  },
};

console.log(`Preço total: ${object.total().toFixed(2)}`);
console.log(object);

const main = document.querySelector("#objetos");

const div = document.createElement("div");
const div2 = document.createElement("div");
const div3 = document.createElement("div");

// main.innerHTML = object.showHTML();
main.appendChild(div);
main.appendChild(div2);
main.appendChild(div3);

div.innerHTML = object.showHTML();
div2.innerHTML = object2.showHTML();
div3.innerHTML = object3.showHTML();
