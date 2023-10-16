class Paciente {
  constructor(nome, peso, altura) {
    this.nome = nome;
    this.peso = peso;
    this.altura = altura;
  }

  imc() {
    return this.peso / (this.altura * this.altura);
  }

  diagnosticar() {
    let imc = this.imc().toFixed(1);
    if (imc < 18.5) {
      return "Abaixo do Peso";
    } else if (imc >= 18.5 && imc < 25) {
      return "Peso Normal";
    } else if (imc >= 25 && imc < 30) {
      return "Sobrepeso";
    } else if (imc >= 30 && imc < 35) {
      return "Obesidade grau 1";
    } else if (imc >= 35 && imc < 40) {
      return "Obesidade grau 2";
    } else if (imc > 40) {
      return "Obesidade grau 3";
    }
  }

  showHTML() {
    let text = `<label>${this.nome}</label>
                <div><label>Peso:</label><label>${this.peso.toFixed(2)} Kg</label>
                <label>Altura:</label><label>${this.altura.toFixed(2)} m</label>
                <label>IMC:</label><label>${this.imc().toFixed(1)}</label></div>
                <label>Diagnóstico:</label><label>${this.diagnosticar()}</label>`;
    return text;
  }
}

const pacientes = [
  new Paciente("André Mattos", 80, 1.8),
  new Paciente("João da Silva", 100, 1.7),
  new Paciente("Maria de Souza", 60, 1.65),
  new Paciente("José de Oliveira", 90, 1.75),
  new Paciente("Silvia Andradae", 60, 1.85),
  new Paciente("Sueli Oliveira", 44, 1.65),
  new Paciente("Pedro de Souza", 110, 1.85),
  new Paciente("Bruno Otávio", 54, 1.73),
];

const main = document.querySelector("#pacientes");

pacientes.forEach((paciente) => {
  const div = document.createElement("div");
  div.innerHTML = paciente.showHTML();
  main.appendChild(div);
});
