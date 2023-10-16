class Triangulo {
  constructor(lado1, lado2, lado3) {
    this.lado1 = lado1;
    this.lado2 = lado2;
    this.lado3 = lado3;
  }

  tipo() {
    if (this.lado1 == this.lado2 && this.lado2 == this.lado3) {
      return "Equilátero";
    } else if (
      this.lado1 == this.lado2 ||
      this.lado1 == this.lado3 ||
      this.lado2 == this.lado3
    ) {
      return "Isósceles";
    } else {
      return "Escaleno";
    }
  }

  showHTML() {
    let text = `
      <label>Lado1: </label><label>${this.lado1}</label>
      <label>Lado2: </label><label>${this.lado2}</label>
      <label>Lado3: </label><label>${this.lado3}</label>
      <label>Tipo: </label><label>${this.tipo()}</label>`;
    return text;
  }
}

const triangulos = [
  new Triangulo(4, 4, 4),
  new Triangulo(2, 5, 6),
  new Triangulo(3, 3, 1),
  new Triangulo(3, 1, 6),
  new Triangulo(5, 5, 5),
];

const main = document.querySelector("#triangulos");

triangulos.forEach((triangulo) => {
  const div = document.createElement("div");
  div.innerHTML = triangulo.showHTML();
  main.appendChild(div);
});
