# atividade-estacionamentoEC

Nome: Luis Carlos Teixeira Costa  
Matrícula: 20240005368

---

# Descrição

Este projeto foi desenvolvido na linguagem C.

O sistema funciona como um estacionamento rotativo, permitindo cadastrar veículos, calcular o tempo de permanência e calcular o valor a pagar.

---

# Tipos de veículos

- Carro → R$ 5/h
- Moto → R$ 3/h
- Caminhonete → R$ 8/h

---

# Regras

- Até 1 hora → valor mínimo
- Acima de 5 horas → desconto de 10%
- Acima de 10 horas → multa de R$ 20

---

# Variáveis Utilizadas

- placa
- tipoVeiculo
- horaEntrada
- horaSaida
- valorHora
- valorFinal

---

# Lógica do Programa

O usuário informa:

- Tipo do veículo
- Placa
- Horário de entrada
- Horário de saída

Depois o sistema calcula:

- Tempo de permanência
- Valor do estacionamento
- Desconto
- Multa
- Valor final

---

# Como Compilar

```bash
gcc main.c -o estacionamento
