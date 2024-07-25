<h1>FreeCell</h1>
<p>FreeCell é um jogo de cartas que utiliza as 52 cartas de um baralho. O objetivo do jogo é mover todas as cartas das pilhas de jogo para as pilhas de saída, seguindo regras específicas de movimentação.</p>

<h2>Regras do Jogo</h2>
<ul>
    <li>Existem 8 pilhas de jogo. No início, 4 pilhas contêm 7 cartas e as outras 4 contêm 6 cartas, distribuídas aleatoriamente e visíveis ao jogador.</li>
    <li>Existem 4 pilhas de saída, inicialmente vazias. As cartas nas pilhas de saída devem estar em ordem (Ás, 2, 3, ..., K) e do mesmo naipe.</li>
    <li>O jogador pode usar 4 posições auxiliares (free cells) para guardar temporariamente uma carta. Cada free cell pode ter no máximo uma carta.</li>
    <li>Movimentos permitidos:
        <ul>
            <li>Para uma free cell desocupada: qualquer carta do topo de uma pilha de jogo.</li>
            <li>Para uma pilha de saída: qualquer carta de uma free cell ou do topo de uma pilha de jogo. Ases podem ser movidos para uma pilha de saída vazia.</li>
            <li>Para o topo de uma pilha de jogo: qualquer carta de uma free cell ou do topo de outra pilha de jogo, seguindo a ordem decrescente e alternando a cor do naipe.</li>
        </ul>
    </li>
    <li>O jogo termina quando todas as cartas são movidas para as pilhas de saída ou quando não há mais movimentos possíveis.</li>
</ul>

<h2>Estruturas Utilizadas</h2>
<p>Para controlar as 12 pilhas necessárias para o jogo (pilhas de jogo e pilhas de saída), são utilizadas até 6 estruturas, cada uma com capacidade fixa para no máximo 26 elementos.</p>

<h2>Como Jogar</h2>
<ol>
    <li>O jogo começa com as cartas distribuídas nas pilhas de jogo.</li>
    <li>O jogador deve escolher uma carta do topo de uma pilha de jogo ou de uma free cell e movê-la para uma pilha de saída, free cell desocupada ou para o topo de outra pilha de jogo, respeitando as regras de movimentação.</li>
    <li>O programa imprime o conteúdo das pilhas após cada jogada e informa qual movimento foi realizado.</li>
    <li>Se um movimento inválido for tentado, o programa avisa o jogador e permite uma nova jogada.</li>
</ol>

<h2>Explicação do Código</h2>
<p>Este projeto consiste em uma implementação de um jogo de cartas, onde diversas funções manipulam as cartas e a estrutura das pilhas. A seguir está a explicação das funções principais:</p>

<h2>Função verificação</h2>
<p>A função <code>verificação</code> tem como objetivo verificar se um movimento feito pelo usuário é válido ou não. Ela recebe diversos parâmetros que representam as diferentes pilhas e cartas no jogo.</p>
<ul>
    <li>Primeiramente, a função lê as entradas <code>retirar</code> e <code>inserir</code>.</li>
    <li>Em seguida, utiliza essas entradas para determinar quais cartas serão movidas.</li>
    <li>A função faz verificações para garantir que as regras do jogo sejam respeitadas, como checar se a pilha está vazia, se as cores das cartas são diferentes, se os números estão em sequência correta, e se as free cells ou pilhas de saída estão disponíveis.</li>
    <li>Se qualquer condição de movimento inválido for encontrada, a função retorna <code>false</code>. Caso contrário, retorna <code>true</code>.</li>
</ul>

<h2>Função CriaCartas</h2>
<p>A função <code>CriaCartas</code> cria todas as cartas de um baralho e as armazena em um vetor de structs.</p>

<ul>
    <li>Ela inicializa as cartas de cada naipe (Espadas, Copas, Paus e Ouros) com seus respectivos números e cores.</li>
    <li>O vetor de structs é preenchido com 52 cartas, sendo 13 de cada naipe.</li>
</ul>

<h2>Função EmbaralhaCartas</h2>
<p>A função <code>EmbaralhaCartas</code> embaralha as cartas criadas e as distribui nas diferentes pilhas de jogo.</p>

<ul>
    <li>Primeiramente, ela embaralha o vetor de cartas usando a função <code>rand()</code> para gerar números aleatórios.</li>
    <li>Em seguida, distribui as cartas embaralhadas nas pilhas, dividindo-as igualmente entre as estruturas de pilhas disponíveis.</li>
</ul>

<h2>Como Compilar e Executar</h2>
<p>Para compilar e executar o programa, siga os passos abaixo:</p>
<ol>
    <li>Abra o terminal ou prompt de comando.</li>
    <li>Navegue até o diretório onde os arquivos <code>Driver.cpp</code>, <code>FreeCell.h</code> e <code>FreeCell.cpp</code> estão localizados.</li>
    <li>Compile os arquivos usando o comando:
        <pre>
g++ Driver.cpp FreeCell.cpp -o arvore_decisao
        </pre>
    </li>
    <li>Execute o programa com o comando:
        <pre>
./arvore_decisao
        </pre>
    </li>
</ol>


<h1>Imagen do prompt de comando do código</h1>

![image](https://github.com/user-attachments/assets/77fa32c0-ac13-4aae-91e6-737fba7aa3fb)
