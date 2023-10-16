class Object {
  constructor(nome, preco, quantidade) {
    this.nome = nome;
    this.preco = preco;
    this.quantidade = quantidade;
  }

  total() {
    return this.preco * this.quantidade;
  }

  showHTML() {
    let string = `
      <label>Nome: </label><label>${this.nome}</label>
      <label>Preço: </label><label>R$${this.preco.toFixed(2)}</label>
      <label>Quantidade: </label><label>${this.quantidade}</label>
      <label>Total: </label><label>R$${this.total().toFixed(2)}</label>`;

    return string;
  }
}

const objects = [];

objects.push(new Object("Caneta", 2.59, 7));
objects.push(new Object("Monitor", 789.9, 3));
objects.push(new Object("Placa de Vídeo", 1289.78, 1));

console.table(objects);

const main = document.querySelector("#objetos");

objects.forEach((element) => {
  const div = document.createElement("div");
  div.innerHTML = element.showHTML();
  main.appendChild(div);
});

// const canetaDiv = document.createElement("div");
// const monitorDiv = document.createElement("div");
// const gpuDiv = document.createElement("div");

// main.appendChild(canetaDiv);
// main.appendChild(monitorDiv);
// main.appendChild(gpuDiv);

// canetaDiv.innerHTML = caneta.showHTML();
// monitorDiv.innerHTML = monitor.showHTML();
// gpuDiv.innerHTML = gpu.showHTML();
