
                                      // Biblioteca de dados //
                                      
#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
#include <ctime> // para rand() //
using namespace std;

// ............................................................................................................................................................ //

                                      // Estrutura das armas e vestimenta //
struct Item {
    string nome;
    bool equipavel;
    int bonusVital, bonusMagia, bonusForca, bonusDefesa;
    string tipo; // Para identificar - ex: "Arma", "Vestimenta", "Consumivel", ... //
    int quantidade;
    string atributos;
    bool venda;
    int valor;
}; // fim struct Item //
    
// ............................................................................................................................................................ //

                                      // Estrutura para drop inimigos e inimigos //
struct Inimigo {
    string nome;
    int vidaBase, vida, atk;
    Item loot[10];   // até 10 itens possíveis e pega a struct item do que dropar //
    int qtdLoot;     // quantidade de itens possíveis //
}; // fim struct Inimigo //

    // Função para sortear drop // ainda entendendo a lógica por trás //
    Item dropItem (const Inimigo &inimigo) {
    int sorteio = rand() % inimigo.qtdLoot;
    return inimigo.loot[sorteio];
} // fim função dropItem //

// ............................................................................................................................................................ //

                                      // Estrutura dos magos //
struct Mago {
    string nomeClasse;
    int vital, mag, forca, def, ouro;
    int vidaCompanion, poderCompanion;
}; // fim struct Mago //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ............................................................................................................................................................ //



                                                        // INICIO PROGRAMAÇÃO //

int main() {
    srand(time(NULL)); // semente para números aleatórios rand () //
    setlocale(LC_ALL, "Portuguese");

// ............................................................................................................................................................ //

                                      // Variáveis //

    int opcao; // uso do menu principal//
    bool menuContinuar = true; // uso do menu principal //
    
    int cenaAtual = 1; // desafio do chefe //
    bool jogoAtivo = true; 
    bool desafio = true; // desafio do chefe //
    int vidasRestantes; // desafio do chefe 3 tentativas //
    int mortes = 0;
    bool fimDeJogo;
    
    bool repetir = false;
    
    bool jogoFeito = false;
    int contadorJornada = 0;
    string historico;
    
    string nomeJogador, companion, continuar;
    int pocao;
    int fase = 0;
    int qtdItens = 0;
    int escolha, acao;
    int indice;
    
    // Struct feitas //
    Mago magoEscolhido;
    Item inventario[20];
    Item vestEquipado = {"Nenhuma", true, 0, 0, 0, 0, "(Vestimenta)", 0, "", false, 0};
    Item cajadoEquipado = {"Nenhum", true, 0, 0, 0, 0, "(Cajado)", 0, "", false, 0};
    Item armaEquipado = {"Nenhuma", true, 0, 0, 0, 0, "(Arma)", 0, "", false, 0};
    
    // Checkpoint de atributos //
    int vitalCheckpoint, magCheckpoint, forcaCheckpoint, defCheckpoint, ouroCheckpoint, pocaoCheckpoint, vidaCompanionCheckpoint, poderCompanionCheckpoint;

// ............................................................................................................................................................ //

                                      // Variáveis Classes de magos e outros // - // Vetor de structs //

    // string nomeClasse, int vital, mag, forca, def, ouro, int vidaCompanion, poderCompanion //
    Mago classesMago[4] = { // Magos //
        {"\033[31mMago do Fogo\033[0m",   70, 60, 15, 50, 50, 30, 40},   // atributos do fogo //
        {"\033[34mMago do Gelo\033[0m",   80, 70, 15, 40, 50, 40, 30},   // atributos do gelo //
        {"\033[32mMago da Terra\033[0m",  90, 50, 15, 70, 50, 50, 25},   // atributos do terra //
        {"\033[33mMago do Raio\033[0m",   60, 90, 15, 35, 50, 35, 50}    // atributos do raio //
    }; // fim inicialização classesMago //
    
    // string nome, bool equipavel, int bonusVital, bonusMagia, bonusForca, bonusDefesa, string tipo, int quantidade, string atributos, bool venda, int valor // 
    Item punhoVazio = {"Punho Vazio", true, 0, 0, 0, 0, "(Arma)", 1, "", false, 0};
    // Armas só mudam status de bonusForca //
    Item espadaMadeira = {"Espada de Madeira", true, 0, 0, 2, 0, "(Arma)", 1, "(Força +2)", true, 3};
    Item espadaLonga = {"Espada Longa", true, 0, 0, 4, 0, "(Arma)", 1, "(Força +4)", true, 10};
    Item espadaFlamejante = {"Espada Flamejante", true, 0, 0, 6, 0, "(Arma)", 1, "(Força +6)", true, 15};
    Item espadaEnferrujada = {"Espada Enferrujada", true, 0, 0, 1, 0, "(Arma)", 1, "(Força +1)", true, 5};
    Item espadaFerro = {"Espada Ferro", true, 0, 0, 0, 0, "(Arma)", 1, "(Força +0)", true, 5};
    // Vestimentas só mudam status de bonusVital e bonusDefesa //
    Item tunicaEstrelar = {"Túnica Estrelar", true, 10, 0, 0, 5, "(Vestimenta)", 1, "(Vida +10, Defesa +5)", false, 0};
    Item tunicaObscura = {"Túnica Obscura", true, 5, 0, 0, 5, "(Vestimenta)", 1, "(Vida +5, Defesa +5)", false, 0};
    // Itens sem valor - apenas venda - Ouro //
    Item peleLobo = {"Pele Lobo", false, 0, 0, 0, 0, "(Consumível)", 1, "", true, 8};
    Item presaLobo = {"Presa Lobo", false, 0, 0, 0, 0, "(Consumível)", 1, "", true, 5};
    // Cajados só mudam status de bonusMagia //
    Item cajadoElemental = {"Cajado Elemental", true, 0, 5, 0, 0, "(Cajado)", 1, "(Magia +5)", false, 0};
    Item cajadoEspectral = {"Cajado Espectral", true, 0, 10, 0, 0, "(Cajado)", 1, "(Magia +10)", false, 0};
    
// ............................................................................................................................................................ //

                                      // Variáveis Inimigos // - // Vetor de structs //
    Inimigo goblin;
    goblin.nome = "\033[32mGoblin\033[0m";
    goblin.vidaBase = 30;
    goblin.vida = 30;
    goblin.atk = 15;
    goblin.loot[0] = espadaEnferrujada, goblin.loot[1] = espadaFerro, goblin.loot[2] = espadaLonga, goblin.loot[3] = espadaFlamejante;
    goblin.qtdLoot = 4;

    Inimigo loboselva;
    loboselva.nome = "\033[32mLobo Selvagem\033[0m";
    loboselva.vidaBase = 30;
    loboselva.vida = 30;
    loboselva.atk = 10;
    loboselva.loot[0] = espadaMadeira, loboselva.loot[1] = espadaFerro, loboselva.loot[2] = peleLobo, loboselva.loot[3] = presaLobo;
    loboselva.qtdLoot = 4;
    
    Inimigo troll;
    troll.nome = "\033[32mTroll\033[0m";
    troll.vidaBase = 30;
    troll.vida = 30;
    troll.atk = 15;
    troll.loot[0] = espadaEnferrujada, troll.loot[1] = espadaFerro, troll.loot[2] = espadaLonga, troll.loot[3] = espadaFlamejante;
    troll.qtdLoot = 4;
    
    Inimigo Ifrit;
    Ifrit.nome = "\033[31mIfrit\033[0m";
    Ifrit.vidaBase = 40;
    Ifrit.vida = 40;
    Ifrit.atk = 10;
    Ifrit.loot[0];
    Ifrit.qtdLoot = 0;

    // Colocar os inimigos num vetor (para ficar escalável)
    Inimigo inimigos[4] = {goblin, loboselva, troll, Ifrit};
    int qtdInimigos = 4;

// ............................................................................................................................................................ //

                                    //                //
                                    // TÍTULO DO JOGO //
                                    // MENU PRINCIPAL //
                                    //                //
                                    
                                    
    do {
	    opcao = 0;
		// solicita ao usuario a variavel option que definira em qual case do switch //
		// entraremos //
		cout << "\n    ======================================= " << endl;
		cout << "   |             MENU PRINCIPAL            |" << endl;
		cout << "   | \033[34m Aventura do Mago Coletor de Cristais\033[0m |" << endl;
		cout << "    ======================================= " << endl;
		cout << "   |                                       |" << endl;
		cout << "   |              (1) Jogar                |" << endl;
		if (jogoFeito)
        cout << "   |        \033[33m(4). Histórico de Jogo\033[0m         |" << endl;
		cout << "   |              (2) Sobre                |" << endl;
		cout << "   |              (3) Sair                 |" << endl;
		cout << "   |                                       |" << endl;
		cout << "    ======================================= " << endl;
		cout << "               Escolha uma opção: ";
		cin >> opcao;
		
		cout << "\033c";
		
		switch (opcao) {  // Menu do jogo //
		
		case 1:

cout<<"\n\033[34m Bem Vindo a Aventura do Mago Coletor de Cristais:\033[0m\n\n";

// Começo do Jogo - Escolha de nome do personagem //
cout<<"\033[33m Digite o nome do seu personagem : \033[0m";
cin >> nomeJogador;
cout<<"\033[33m Digite o nome do seu companion: \033[0m";
cin >> companion;
cout<<endl;

                                    //1ª Escolha do jogo//
               /////////////////////////////////////////////////////////////////
               
    cout<<" Escolha sua classe de mago : "<<endl; 
    cout<<"   1.  "<<classesMago[0].nomeClasse<<"\t"<<" 2.  "<<classesMago[1].nomeClasse<<"\t"
        <<" 3.  "<<classesMago[2].nomeClasse<<"\t"<<" 4.  "<<classesMago[3].nomeClasse<<endl;

    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
 do {
        cout<<"\033[33m   Sua escolha será : \033[0m";
        cin>>escolha;

        if (escolha >= 1 && escolha <= 4) {
            magoEscolhido = classesMago[escolha - 1]; // pega o mago correto do vetor - sempre começa com zero //
        } else {
            cout<<"\033[31m   Esse Mago não existe! Digite um número de 1 a 4.\n\n\033[0m";
        }
    } while (escolha < 1 || escolha > 4); // fim do-while escolha classe //
    
               /////////////////////////////////////////////////////////////////

                                    //Atualização de atributos//
    cout<<"\n   E aqui está sua ficha de atributos iniciais"<<endl;
    cout<<"\033[32m   Nome do Mago : \033[0m"<<"\033[38;5;208m"<<nomeJogador<<"\033[0m"<<", o "<<magoEscolhido.nomeClasse<<endl;
    cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\t"
        <<"\033[32m Força : \033[0m"<<magoEscolhido.forca<<"\t"<<"\033[32m Defesa : \033[0m"<<magoEscolhido.def<<"\t"
        <<"\033[32m Ouro : \033[0m"<<magoEscolhido.ouro<<endl;
    cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<endl;
    cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
        <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;

//Para não ir direto para a próxima escolha e perder a leitura do resultado//
cout<<"\n\033[34m  Aperte ENTER para cotinuar a jornada : \033[0m";
cin.ignore(), cin.ignore();

cout<<"\n\033[32m  ============================================================================================================  \033[0m\n";

                                    //2ª Escolha do jogo//
               /////////////////////////////////////////////////////////////////
               
    cout<<"\n Escolha a vestimenta que deseja se equipar antes de começar a aventura?"<<endl;
    
    cout<<"   1. Vestimenta Elemental : "<<tunicaEstrelar.nome<<tunicaEstrelar.atributos<<", "<<cajadoElemental.nome<<cajadoEspectral.atributos<<" e Poções (2)"<<endl;
    cout<<"   2. Vestimenta Espectral : "<<tunicaObscura.nome<<tunicaObscura.atributos<<", "<<cajadoEspectral.nome<<cajadoEspectral.atributos<<" e Poções (2)"<<endl;

    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //

do { // abre do-while escolha vestimenta //
    cout << "\033[33m   Sua escolha será : \033[0m";
    cin >> escolha;

    if (escolha == 1) {
        vestEquipado = tunicaEstrelar;
        cajadoEquipado = cajadoElemental;
        pocao = 2;
    }
    else if (escolha == 2) {
        vestEquipado = tunicaObscura;
        cajadoEquipado = cajadoEspectral;
        pocao = 2;
    }
    else {
        cout << "\033[31m   Essa vestimenta não existe! Digite um número de 1 a 2.\n\n\033[0m";
    }
} while (escolha != 1 && escolha != 2); // fim do-while escolha vestimenta //
    
               /////////////////////////////////////////////////////////////////

                                    //Atualização de atributos//
    cout<<"\n   Atributos atualizados"<<endl;
    cout<<"\033[32m   Nome do Mago : \033[0m"<<"\033[38;5;208m"<<nomeJogador<<"\033[0m, o "<<magoEscolhido.nomeClasse<<endl;
    cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\033[33m+"<<vestEquipado.bonusVital<<"\033[0m\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\033[33m+"<<cajadoEquipado.bonusMagia<<"\033[0m\t"
        <<"\033[32m Força : \033[0m"<<magoEscolhido.forca<<"\033[33m+"<<armaEquipado.bonusForca<<"\033[0m\t"<<"\033[32m Defesa : \033[0m"<<magoEscolhido.def<<"\033[33m+"<<vestEquipado.bonusDefesa<<"\033[0m\t"
        <<"\033[32m Ouro : \033[0m"<<magoEscolhido.ouro<<endl;
    cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<"\t"
        <<"\033[32m Poções : \033[0m"<<pocao<<endl;
    cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
        <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;
        
//Para não ir direto para a próxima escolha e perder a leitura do resultado//
cout<<"\n\033[34m  Aperte ENTER para cotinuar a jornada : \033[0m";
cin.ignore(), cin.ignore();

cout<<"\n\033[32m  ============================================================================================================  \033[0m\n";

                                    //3ª Escolha do jogo//
               /////////////////////////////////////////////////////////////////
               
                        //Aqui entraremos em uma batalha padrão do jogo//
               

repetir = true;

do{ // abre do-while principal das bifurcações //
    cout<<"\n Seguindo em frente na sua jornada após sair da escola de magos você busca se aventurar na floresta proibida. Após uma breve caminhada uma bifurcação inusitada surge na sua visão."<<endl;
    cout<<"   1. Passar pelo local com árvores levando as sombras da floresta (batalha) : "<<endl;
    cout<<"   2. Passar por uma fenda de um penhasco estreito, porém com o caminho cheio de vinhas (batalha)  : "<<endl;
    cout<<"\033[33m   Sua escolha será : \033[0m";
    cin>>escolha;
        
        
        // Usaremos a escolha para criar uma switch para batalhas e saida apenas após o termino ou morte //
        switch (escolha) { // abre switch principal das opções //
            
            case 1: { // abre case 1 //
                
                // randomico o encontro dos inimigos e quantidade de vezes - pega no vetor e structs de inimigos //
                for (int fase = 0; fase < 2; fase++) { // abre for combate fase //
                do {
                    indice = rand() % qtdInimigos;
                } while (inimigos[indice].nome == "\033[31mIfrit\033[0m");
                Inimigo atual = inimigos[indice];
                atual.vida = atual.vidaBase;
                
                // Aqui será definido o inimigo que irá aparecer no jogo randomico //
                cout << "\n  ================================================================\n";
                cout << "             Batalha " << fase+1 << " Voce encontrou um " << atual.nome << "\n";
                cout << "             Vida : " << atual.vida << "\n";
                // ________________________________________________________________________________________//
                
                                            // Entraremos no duelo //
                // ________________________________________________________________________________________//
                
                while ((magoEscolhido.vital + vestEquipado.bonusVital) > 0 && atual.vida > 0) { // abre while combate //
                    
                    cout << "\n             Escolha uma acao:\n";
                    cout << "             1 - Atacar\n";
                    cout << "             2 - Usar Pocao (" << pocao << " restantes)\n";
                    cout << "             3 - Defender\n";
                    cout << "             Digite: ";
                    cin >> acao;
                    cout << endl;
                    
                    if (acao == 1) {
                        int dano = (magoEscolhido.forca + armaEquipado.bonusForca);
                        cout << "             " << nomeJogador << " ataca e causa " << dano << " de dano!\n";
                        atual.vida -= dano;
                    }
                    else if (acao == 2) {
                        if (pocao > 0) {
                            magoEscolhido.vital = min(magoEscolhido.vital + 10, magoEscolhido.vital + vestEquipado.bonusVital);
                            pocao--;
                            cout << "             Voce usou uma pocao e recuperou 10 de vida!\n";
                        } else {
                            cout << "             Voce nao tem mais pocoes!\n";
                        }
                    }
                    else if (acao == 3) {
                        cout << "             " << nomeJogador << " se defende, recebendo menos dano!\n";
                    }
                    else {
                        cout << "\033[31m             Opcao invalida!\033[0m\n";
                        continue;
                    }
                // ________________________________________________________________________________________//
                
                                        // Turno do inimigo (se ainda estiver vivo) //
                // ________________________________________________________________________________________//  
                
                    if (atual.vida > 0) {
                        int danoInimigo = atual.atk + (rand() % 5);
                        if (acao == 3) danoInimigo /= 2; // defesa reduz dano //
                        magoEscolhido.vital -= danoInimigo;
                        cout << "             " << atual.nome << " ataca e causa " << danoInimigo << " de dano!\n";
                    }
                } // fecha while combate //
                // ________________________________________________________________________________________//
                
                                                // Morte do jogador //
                // ________________________________________________________________________________________//
                
                if ((magoEscolhido.vital + vestEquipado.bonusVital) <= 0) {
                cout << "\n             " << nomeJogador << " foi derrotado! Fim de jogo.\n";
                return 0;
            }
                // ________________________________________________________________________________________//
                
                                                // Vitória do jogador //
                // ________________________________________________________________________________________//
                
                cout << "\n             Voce derrotou o " << atual.nome << "!\n";
                // ________________________________________________________________________________________//
                
                                    // Drop do item com a vitória sobre o inimigo //
                // ________________________________________________________________________________________//
                
                Item itemDropado = dropItem(atual);
                inventario[qtdItens] = itemDropado;
                qtdItens++;
                cout << "             " << atual.nome << " dropou: " << itemDropado.nome << "!\n";
                cout << "\n  ================================================================\n";                
                } // fecha for (fase) do case 1 //
                break;
            } // fecha bloco case 1 //
                // ________________________________________________________________________________________//
                
            case 2: { // abre case 2 //
                
                // Aqui será definido o inimigo que irá aparecer no jogo //
                loboselva.vida = loboselva.vidaBase;
                for (int fase = 0; fase < 1; fase++) { // abre for fase (case 2) //
                    
                cout << "\n================================================================\n";
                cout << "             Batalha " << fase+1 << " Voce encontrou um " << loboselva.nome << "\n";
                cout << "             Vida : " << loboselva.vida << "\n";
                // ________________________________________________________________________________________//
                
                                            // Entraremos no duelo //
                // ________________________________________________________________________________________//
                
                while ((magoEscolhido.vital + vestEquipado.bonusVital) > 0 && loboselva.vida > 0) { // abre while combate (lobo) //
                    
                    cout << "\n             Escolha uma acao:\n";
                    cout << "             1 - Atacar\n";
                    cout << "             2 - Usar Pocao (" << pocao << " restantes)\n";
                    cout << "             3 - Defender\n";
                    cout << "             Digite: ";
                    cin >> acao;
                    cout << endl;
                    
                    if (acao == 1) {
                    int dano = (magoEscolhido.forca + armaEquipado.bonusForca);
                    cout << "             " << nomeJogador << " ataca e causa " << dano << " de dano!\n";
                    loboselva.vida -= dano;
                        
                    }
                    else if (acao == 2) {
                        if (pocao > 0) {
                        magoEscolhido.vital = min(magoEscolhido.vital + 10, magoEscolhido.vital + vestEquipado.bonusVital);
                        pocao--;
                        cout << "             Voce usou uma pocao e recuperou 10 de vida!\n";
                        } else {
                            cout << "             Voce nao tem mais pocoes!\n";
                       }
                    }
                    else if (acao == 3) {
                        cout << "             " << nomeJogador << " se defende, recebendo menos dano!\n";
                    }
                    else {
                        cout << "\033[31m             Opcao invalida!\033[0m\n";
                        continue;
                    }
                // ________________________________________________________________________________________//
                
                                        // Turno do inimigo (se ainda estiver vivo) //
                // ________________________________________________________________________________________// 
                
                    if (loboselva.vida > 0) {
                        int danoInimigo = loboselva.atk + (rand() % 5);
                        if (acao == 3) danoInimigo /= 2; // defesa reduz dano //
                        magoEscolhido.vital -= danoInimigo;
                        cout << "             " << loboselva.nome << " ataca e causa " << danoInimigo << " de dano!\n";
                    }
                } // fecha while combate (lobo) //
                // ________________________________________________________________________________________//
                
                                                // Morte do jogador //
                // ________________________________________________________________________________________//
                
                if ((magoEscolhido.vital + vestEquipado.bonusVital) <= 0) {
                cout << "\n             " << nomeJogador << " foi derrotado! Fim de jogo.\n";
                return 0;
            }
                // ________________________________________________________________________________________//
                
                                                // Vitória do jogador //
                // ________________________________________________________________________________________//
                
                cout << "\n             Voce derrotou o " << loboselva.nome << "!\n";
                // ________________________________________________________________________________________//
                
                                    // Drop do item com a vitória sobre o inimigo //
                // ________________________________________________________________________________________//
                
                Item itemDropado = dropItem(loboselva);
                inventario[qtdItens] = itemDropado;
                qtdItens++;
                cout << "             " << loboselva.nome << " dropou: " << itemDropado.nome << "!\n";
                cout << "\n  ================================================================\n"; 
                } // fecha for (fase) do case 2 //
                break;
                // ________________________________________________________________________________________//
            } // fecha bloco case 2 //
            
        default: // caso opção inválida no switch //
            cout << "\033[31m   Opção inválida! Digite 1 ou 2.\n\n\033[0m";
            continue;
        } // fim switch (escolha) //

    cout<<"\n   Atributos atualizados"<<endl;
    cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\033[33m+"<<vestEquipado.bonusVital<<"\033[0m\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\033[33m+"<<cajadoEquipado.bonusMagia<<"\033[0m"<<endl;
    cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
        <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;

    do { // abre do-while pergunta continuar/voltar //
        cout << "\n O que deseja fazer agora?\n";
        cout << "   1. Continuar a aventura\n";
        cout << "   2. Voltar para a bifurcacao e batalhar mais\n";
        cout<<"\033[33m   Sua escolha será : \033[0m";
        cin >> escolha;
        
        cout<<"\n\033[32m  ============================================================================================================  \033[0m\n";
        
        if (escolha == 1) {
            repetir = false; // sai do loop, continua a aventura //
        } 
        else if (escolha == 2) {
            repetir = true; // volta para o início da bifurcação //
        } 
        else {
            cout << "\033[31m   Opcao invalida, digite novamente...\033[0m\n";
        }
    } while (escolha != 1 && escolha != 2); // fim do-while pergunta continuar/voltar //

} while (repetir); // fim do-while principal das bifurcações //


// Após sair do loop de repetir: //
    cout<<"\n   Atributos atualizados"<<endl;
    cout<<"\033[32m   Nome do Mago : \033[0m"<<nomeJogador<<", o "<<magoEscolhido.nomeClasse<<endl;
    cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\033[33m+"<<vestEquipado.bonusVital<<"\033[0m\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\033[33m+"<<cajadoEquipado.bonusMagia<<"\033[0m\t"
        <<"\033[32m Força : \033[0m"<<magoEscolhido.forca<<"\033[33m+"<<armaEquipado.bonusForca<<"\033[0m\t"<<"\033[32m Defesa : \033[0m"<<magoEscolhido.def<<"\033[33m+"<<vestEquipado.bonusDefesa<<"\033[0m\t"
        <<"\033[32m Ouro : \033[0m"<<magoEscolhido.ouro<<endl;
    cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<"\t"
        <<"\033[32m Poções : \033[0m"<<pocao<<endl;
    cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
        <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;


do { // abre do-while para escolha abrir inventário //
    cout<<"\n   Deseja acessar invetário? (1. Sim/ 2. Não)"<<endl;
    cout<<"\033[33m   Sua escolha será : \033[0m"; 
    cin>>escolha;
    
    if (escolha == 1) {
        int escolhaInv = -1;
    do { // abre do-while inventário (loop até 0) //
        // Mostrar inventário e permitir equipar
        cout << "\n   ====== Inventário ======\n";
        for (int i = 0; i < qtdItens; i++) {
            cout << "   " << i+1 << ". " << inventario[i].nome 
                 << " " << inventario[i].tipo << " "
                 << inventario[i].atributos << "\n";
        }
        cout << "   0. Voltar\n";
        cout << "   ========================\n";
        
        cout << "   Escolha um item para equipar: ";
        cin >> escolhaInv;
        
        if (escolhaInv > 0 && escolhaInv <= qtdItens) {
            Item itemEscolhido = inventario[escolhaInv - 1];
            
            // Agora checa se é arma ou vestimenta
            if (itemEscolhido.tipo == "(Arma)") {
            // troca: o antigo vai para o inventário no lugar do novo
            Item temp = armaEquipado;
            armaEquipado = itemEscolhido;
            inventario[escolhaInv - 1] = temp;
            
            cout<<"   Equipamento atualizado!"<<endl;
            cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<endl;
            } 
            else if (itemEscolhido.tipo == "(Vestimenta)") {
            Item temp = vestEquipado;
            vestEquipado = itemEscolhido;
            inventario[escolhaInv - 1] = temp;
            
            cout<<"   Equipamento atualizado!"<<endl;
            cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<endl;
            } 
            else if (itemEscolhido.tipo == "(Cajado)"){
            Item temp = cajadoEquipado;
            cajadoEquipado = itemEscolhido;
            inventario[escolhaInv - 1] = temp;
            
            cout<<"   Equipamento atualizado!"<<endl;
            cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<endl;
            }
            else {
            cout << "\033[31m   Esse item não pode ser equipado!\033[0m\n";
            }
        }
        else if (escolhaInv == 0){
            cout << "   Voltando...\n";
        }
        else { 
        cout<<"\033[31m Esse opção não existe! Digite um número válido.\n\n\033[0m"; 
        }
    } while (escolhaInv != 0); // fim do-while inventário (loop até 0) //
    } // fim if (escolha == 1) //
    else if (escolha == 2) {
        cout << "   Você escolheu não abrir o inventário.\n";
    } // fim else if (escolha == 2) //
    else { 
        cout << "\033[31m   Essa opção não existe! Digite 1 ou 2.\n\n\033[0m"; 
    } // fim else inválido //
} while (escolha != 2); // fim do-while abrir inventário //


//Para não ir direto para a próxima escolha e perder a leitura do resultado//
cout<<"\n\033[34m  Aperte qualquer número para cotinuar a jornada : \033[0m";
cin>>continuar;




























cout<<"           ______________________________________________________________________ "<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |              ^^^^^^                       ^^^^^^^^^^^^               |"<<endl;
cout<<"          |             |      |                     |            |              |"<<endl;
cout<<"          |            (Ferreiro)                  (Loja do Mercador)            |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |              ^^^^^^^                    ^^^^^^^^^^^^^^               |"<<endl;
cout<<"          |             |       |                  |              |              |"<<endl;
cout<<"          |            ( Pousada )                (Loja Mago Arcano)             |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"          |                                                                      |"<<endl;
cout<<"           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "<<endl;

do {
    cout<<"\n   Você está no vilarejo do reino. Digite o número da local que deseja visitar. "<<endl;
    cout<<"   1. Ferreiro/ 2. Loja do Mercador/ 3. Pousada/ 4. Loja do Mago Arcano/ 5. Sair do Vilarejo "<<endl;
    cout<<"\033[33m   Sua escolha será : \033[0m"; 
    cin>>escolha;
    
    if (escolha == 1){
        
    }
    else if (escolha == 2) {
        int escolhaVenda = -1;
        do {
    cout << "\n   ====== Loja do Mercador ======\n";
    cout << "   Ouro atual: \033[33m" << magoEscolhido.ouro << " moedas\033[0m\n\n";

    if (qtdItens == 0) {
        cout << "   Seu inventário está vazio!\n";
        break;
    }

    for (int i = 0; i < qtdItens; i++) {
        cout << "   " << i+1 << ". " << inventario[i].nome 
             << " " << inventario[i].tipo
             << " - Valor: " << inventario[i].valor << "g\n";
    }
    cout << "   0. Voltar\n";
    cout << "   ==============================\n";
    
    cout << "   Escolha um item para vender: ";
    cin >> escolhaVenda;

    if (escolhaVenda > 0 && escolhaVenda <= qtdItens) {
        Item itemEscolhido = inventario[escolhaVenda - 1];
        cout << "\n   Deseja vender " << itemEscolhido.nome 
             << " por " << itemEscolhido.valor << "g? (1. Sim / 2. Não): ";
        int confirmar;
        cin >> confirmar;

        if (confirmar == 1) {
            magoEscolhido.ouro += itemEscolhido.valor;

            // Remover o item do inventário (compactar)
            for (int j = escolhaVenda - 1; j < qtdItens - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            qtdItens--;

            cout << "\033[32m   Você vendeu " << itemEscolhido.nome 
                 << " e ganhou " << itemEscolhido.valor 
                 << "g!\033[0m\n";
            cout << "   Ouro atual: " << magoEscolhido.ouro << "g\n";
        } else {
            cout << "   Venda cancelada.\n";
        }
    } 
    else if (escolhaVenda == 0) {
        cout << "   Você decidiu sair da loja.\n";
    } 
    else {
        cout << "\033[31m   Escolha inválida!\033[0m\n";
    }

} while (escolhaVenda != 0);
        
    } 
    else if (escolha == 3) {
    } 
    else if (escolha == 4) {
    } 
    else if (escolha == 5) {
    } 
    else { 
        cout << "\033[31m   Essa opção não existe! Digite de 1 a 5.\n\n\033[0m"; 
    } // fim else inválido //
} while (escolha != 5); // fim do-while abrir inventário //  
    
    
    
    



//Para não ir direto para a próxima escolha e perder a leitura do resultado//
cout<<"\n\033[34m  Aperte qualquer número para cotinuar a jornada : \033[0m";
cin>>continuar;

// ............................................................................................................................................................ //

                                                    // BATALHA CONTRA O IFRIT //

                // Checkpoint de atributos - reseta status caso morra dentro da Batalha contra o Ifrit //
                
vitalCheckpoint=magoEscolhido.vital, magCheckpoint=magoEscolhido.mag, forcaCheckpoint=magoEscolhido.forca, defCheckpoint=magoEscolhido.def;
ouroCheckpoint=magoEscolhido.ouro, pocaoCheckpoint=pocao;
vidaCompanionCheckpoint=magoEscolhido.vidaCompanion, poderCompanionCheckpoint=magoEscolhido.poderCompanion;

    fimDeJogo = false; 
    
while (desafio && mortes < 3) {

        
        switch (cenaAtual) { // inicio switch //
            
            // ===== Batalha turno 1 =====
            case 1: {
                
                cout<<"\n\033[31m  ============================================================================================================  \033[0m\n";
                cout<<"\n\033[31m                A GRANDE BATALHA CHEGOU - A BUSCA PELO CRISTAL DA BESTA DE FOGO IFRIT\033[0m\n"; 
                cout<<"\n\033[31m  ============================================================================================================  \033[0m\n";
                
                // Mostra as vidas restantes em formato de corações
                int vidasRestantes = 3 - mortes;
                cout<<"\n\033[32m   Vidas :   \033[0m";
                for (int i = 0; i < vidasRestantes; i++) {
                    cout<< " ❤️ ";
                }
                
                cout<<"\033[32m   Nome do Mago : \033[0m"<<nomeJogador<<", o "<<magoEscolhido.nomeClasse<<endl;
                cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\033[33m+"<<vestEquipado.bonusVital<<"\033[0m\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\033[33m+"<<cajadoEquipado.bonusMagia<<"\033[0m\t"
                    <<"\033[32m Força : \033[0m"<<magoEscolhido.forca<<"\033[33m+"<<armaEquipado.bonusForca<<"\033[0m\t"<<"\033[32m Defesa : \033[0m"<<magoEscolhido.def<<"\033[33m+"<<vestEquipado.bonusDefesa<<"\033[0m\t"
                    <<"\033[32m Ouro : \033[0m"<<magoEscolhido.ouro<<endl;
                cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<"\t"
                    <<"\033[32m Poções : \033[0m"<<pocao<<endl;
                cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
                    <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;
                    
                cout<<"\n\033[32m  ============================================================================================================  \033[0m\n";
                
                bool morreuNestaCena = false;
                
                // Aqui será definido o inimigo que irá aparecer no jogo //
                
                Ifrit.vida = Ifrit.vidaBase;
                    
                cout << "\n================================================================\n";
                cout << "             Batalha " << fase+1 << " Voce encontrou um " << Ifrit.nome << "\n";
                cout << "             Vida : " << Ifrit.vida << "\n";
                
                // ________________________________________________________________________________________//
                
                                            // Entraremos no duelo //
                // ________________________________________________________________________________________//
                
                while ((magoEscolhido.vital + vestEquipado.bonusVital) > 0 && Ifrit.vida > 0) {
                    
                    cout << "\n             Escolha uma acao:\n";
                    cout << "             1 - Atacar\n";
                    cout << "             2 - Usar Pocao (" << pocao << " restantes)\n";
                    cout << "             3 - Defender\n";
                    cout << "             Digite: ";
                    cin >> acao;
                    cout << endl;
                    
                    if (acao == 1) {
                    int dano = (magoEscolhido.forca + armaEquipado.bonusForca);
                    cout << "             " << nomeJogador << " ataca e causa " << dano << " de dano!\n";
                    Ifrit.vida -= dano;
                        
                    }
                    else if (acao == 2) {
                        if (pocao > 0) {
                        magoEscolhido.vital += 20;
                        pocao--;
                        cout << "             Voce usou uma pocao e recuperou 20 de vida!\n";
                        } else {
                            cout << "             Voce nao tem mais pocoes!\n";
                       }
                    }
                    else if (acao == 3) {
                        cout << "             " << nomeJogador << " se defende, recebendo menos dano!\n";
                    }
                    else {
                        cout << "\033[31m             Opcao invalida!\033[0m\n";
                        continue;
                    }
                // ________________________________________________________________________________________//
                
                                        // Turno do inimigo (se ainda estiver vivo) //
                // ________________________________________________________________________________________// 
                
                    if (Ifrit.vida > 0) {
                        int danoInimigo = Ifrit.atk + (rand() % 5);
                        if (acao == 3) danoInimigo /= 2; // defesa reduz dano //
                        magoEscolhido.vital -= danoInimigo;
                        cout << "             " << Ifrit.nome << " ataca e causa " << danoInimigo << " de dano!\n";
                    }
                }
                // ________________________________________________________________________________________//
                
                                                // Morte do jogador //
                // ________________________________________________________________________________________//
                
                    // Checa se o jogador morreu DEPOIS do turno do inimigo
                    if ((magoEscolhido.vital + vestEquipado.bonusVital) <= 0) {
                        mortes++; // soma mais uma morte
                        
                        if (mortes >= 3) {
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            cout<<"\n\033[31m             VOCÊ FOI DERROTADO DEFINITIVAMENTE! \033[0m\n";
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            
                        // marque flags para sair dos loops externos corretamente
                            desafio = false;
                            fimDeJogo = true;
                            jogoFeito = true; // se desejar marcar histórico
                            break; // encerra o programa //
                        }
                        
                        cout<<"\n\033[31m                  Você foi derrotado...";
                        cout<<"\n                O tempo retrocede e você volta ao seu último checkpoint!\033[0m\n";
                        
                        
                        // Restaura atributos do checkpoint
                        magoEscolhido.vital = vitalCheckpoint;
                        magoEscolhido.mag = magCheckpoint;
                        magoEscolhido.forca = forcaCheckpoint;
                        magoEscolhido.def = defCheckpoint;
                        magoEscolhido.ouro = ouroCheckpoint;
                        pocao = pocaoCheckpoint;
                        magoEscolhido.vidaCompanion = vidaCompanionCheckpoint;
                        magoEscolhido.poderCompanion = poderCompanionCheckpoint;
                        
                        // marca que morreu nesta cena e sai do loop de combate
                        morreuNestaCena = true;
                    }
                
                // ________________________________________________________________________________________//
                
                                                // Vitória do jogador //
                // ________________________________________________________________________________________//
                   else {
                cout << "\n             Voce derrotou o " << Ifrit.nome << "!\n";
                // ________________________________________________________________________________________//
                
                                    // Drop do item com a vitória sobre o inimigo //
                // ________________________________________________________________________________________//
                
                Item itemDropado = dropItem(Ifrit);
                inventario[qtdItens] = itemDropado;
                qtdItens++;
                cout << "             " << Ifrit.nome << " dropou: " << itemDropado.nome << "!\n";
                cout << "\n  ================================================================\n";
                
                desafio = false; 
                // ________________________________________________________________________________________//
            }

            // Se morreu nesta cena, encerra o case para que o while externo trate a reexecução
            if (morreuNestaCena) {
                // não alterar desafio aqui; o while externo vai continuar porque mortes < 3
                break; // sai do case 1 (retorna ao switch do while externo)
            }

            // fim do case 1
            break;
        } // fim case 1

        default: {
            // caso padrão: encerra o desafio/loop de chefe de forma limpa
            desafio = false;
            jogoAtivo = false;
        }
    } // fim switch

    // Se a flag fimDeJogo foi acionada (derrota definitiva), saia do loop principal do chefe
    if (fimDeJogo) {
        break;
    }

} // fim while (desafio && mortes < 3)

mortes = 0;
    
// Após sair do loop de repetir: //
    cout<<"\n   Atributos atualizados"<<endl;
    cout<<"\033[32m   Nome do Mago : \033[0m"<<nomeJogador<<", o "<<magoEscolhido.nomeClasse<<endl;
    cout<<"\033[32m   Vitalidade : \033[0m"<<magoEscolhido.vital<<"\033[33m+"<<vestEquipado.bonusVital<<"\033[0m\t"<<"\033[32m Magia : \033[0m"<<magoEscolhido.mag<<"\033[33m+"<<cajadoEquipado.bonusMagia<<"\033[0m\t"
        <<"\033[32m Força : \033[0m"<<magoEscolhido.forca<<"\033[33m+"<<armaEquipado.bonusForca<<"\033[0m\t"<<"\033[32m Defesa : \033[0m"<<magoEscolhido.def<<"\033[33m+"<<vestEquipado.bonusDefesa<<"\033[0m\t"
        <<"\033[32m Ouro : \033[0m"<<magoEscolhido.ouro<<endl;
    cout<<"\033[32m   Vestimenta : \033[0m"<<vestEquipado.nome<<"\t"<<"\033[32m Cajado : \033[0m"<<cajadoEquipado.nome<<"\t"<<"\033[32m Arma : \033[0m"<<armaEquipado.nome<<endl;
    cout<<"\033[32m   Poções : \033[0m"<<pocao<<endl;
    cout<<"\033[32m   Primeiro Companion : \033[0m"<<"\033[33m"<<companion<<"\033[0m"<<"\t"
        <<"\033[32m Vida : \033[0m"<<magoEscolhido.vidaCompanion<<"\t"<<"\033[32m Poder : \033[0m"<<magoEscolhido.poderCompanion<<endl;
  
//Para não ir direto para a próxima escolha e perder a leitura do resultado//
cout<<"\n\033[34m  Aperte qualquer número para cotinuar a jornada : \033[0m";
cin>>continuar;

            cout << "\033c";
            
            break;
         
		case 2: // Sobre //
			// Menu do case 2 que leva a opção "sobre" //
			
			cout << "\033c";
			cout << endl;
			cout << "    ======================================= " << endl;
			cout << "   |                 SOBRE                 |" << endl;
			cout << "   | \033[34m Aventura do Mago Coletor de Cristais\033[0m |" << endl;			
			cout << "    ======================================= " << endl;
			cout << "   |            Desenvolvedores:           |" << endl;
			cout << "   |                                       |" << endl;
			cout << "   |         - Luiz Miguel Silvino         |" << endl;
			cout << "   |       - Cassiano Ricardo Onorio       |" << endl;
			cout << "   |                                       |" << endl;
			cout << "    ======================================= " << endl;
			cin.ignore();
			cout << "    Aperte ENTER para voltar ao Menu Principal...";
			cin.ignore();
			cout << "\033c";
			
			break;
			
		case 3: // Sair //
         
			menuContinuar = false; 
			break;
			
		case 4:
            if (jogoFeito) {
                cout << "\n        = HISTÓRICO =  \n";
                cout<< "\n   Quantidade de jornadas realizadas : \033[33m"<<contadorJornada<<"\033[0m"<<endl;
                cout<<"\033[32m  ============================================================================================================  \033[0m\n";
                cout << historico;
                cin.ignore();
                cout << "\n    Aperte ENTER para voltar ao Menu Principal...";
                cin.ignore();
                cout << "\033c";
                
			break;
            } 
            else {
                cout << "\033c";
            }
        break;
        
		}
		
	} while (menuContinuar);

return 0;

}