# Cadastro-Aluno
Projeto de cadastro de aluno e manipulação de informações em C ainda em desenvolvimento!

# TO-DO

- [x] Cadastrar alunos;
- [x] Printar as informações cadastradas;
- [x] Remover aluno pelo RGA;
- [x] Atualizar notas de um aluno através do RGA;
- [ ] Exibir o nome, as três notas e a MA de todos os alunos aprovados na disciplina, ordenados por nome;
- [ ] Exibir o nome, as três notas e a MA de todos os alunos reprovados na disciplina, ordenados decrescentemente pela MA(média) obtida. Caso existam dois ou mais alunos com a mesma MA, esses alunos devem ser exibidos em ordem alfabética;
- [x] Fazer uma função recursiva da busca no vetor de registros de aluno pelo RGA, a função deve retornar a posição do vetor em que o registro do aluno está armazenado, caso contrário, deve retornar -1;
- [ ] Fazer uma função que busca os dados apenas por aluno de acordo com o RGA digitado;
- [ ] Ajustar a função do case 4 para poder trazer o resultado ordenado por nome dos alunos;



# Problems to fix-it

- [ ] No case 3 so switch está com problema na atualização dos valores das notas;
- [ ] Verificar a função buscaAluno(), pois não deu certo quando fui tentar executar a remoção de um aluno como no case 2 ou de atualizar os valores no case 3;
- [ ] O sistema funciona de forma linear de cadastrar os alunos, atualizar e excluir. Porém se caso eu precisar cadastrar um novo aluno ele apaga os outros alunos que já estavam cadastrados;
- [ ] Quando coloca notas maiores do que 10 ele deixa passar pois não tem nenhum verificador de limite de nota a ser digitado;
- [ ] Na atualização de valores quando informa um RGA aleatório ele permiti digitar os valores e com isso o sistema acaba atualizando sempre o primeiro registro;
