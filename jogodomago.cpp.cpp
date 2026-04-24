// ............................................................................................................................................................ //

                                    // Biblioteca de dados //
#include <iostream>
#include <string>
#include <clocale>
#include <ctime>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                    // INICIO PROGRAMAÇÃO //

int main() {

setlocale(LC_ALL, "portuguese"); // Configuração do locale para português no Windows // - não parece que funcionou //
srand(time(NULL));

// ............................................................................................................................................................ //

                                    // Tipos e Variaveis para calcular e alterar o padrão do jogo //

int opcao; // uso do menu principal//
bool menuContinuar = true; // uso do menu principal //

string nome, mago; // nome e tipo mago // 
int escolha, escolha20; // molde para calcular as escolhas no if/else if em cada cena//

float vital, mag, forca, def, ouro; // atributos do personagem //
float bvital, bmag, bforca, bdef, bvida, bdef_pro; // para bonus //
float pot; // itens //

float vitalInicial, magInicial, forcaInicial, defInicial; // feito para guardar a escolha de mago e calcular na mecânica de repouso e level up //

float vitalCheckpoint, magCheckpoint, forcaCheckpoint, defCheckpoint, ouroCheckpoint, potCheckpoint; // checkpoint atributos antes de um batalha de chefe //
float bvitalCheckpoint, bmagCheckpoint, bforcaCheckpoint, bdefCheckpoint; // checkpoint bonus atributos antes de um batalha de chefe //

int dado, i; // para usar a mecâcnica de rand() //

string opcao1, opcao2, opcao3; // teste opcoes //

int cenaAtual = 1; // desafio do chefe //
bool jogoAtivo = true, desafio = true; // desafio do chefe //
int vidasRestantes; // desafio do chefe 3 tentativas //
int mortes = 0; // contador de mortes - desafio dos chefes //

bool jogoFeito = false; // controla se já jogou ao menos uma vez //
string historico = "";  // armazena todas as jogadas em texto //
int contadorJornada = 0;
bool fimDeJogo;

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
            
            cout<<"\033[34m Bem Vindo a Aventura do Mago Coletor de Cristais:\033[0m\n\n";
            contadorJornada++;
            
            // Escolha de nome do personagem //
            cout<<"\033[33m Digite o nome do seu personagem : \033[0m";
            cin.ignore();
            getline(cin, nome);
            
                                        //1ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n Escolha sua classe de mago : "<<endl; // Escolha do tipo do mago no jogo // 
            cout<<"   1.\033[31m Mago de Fogo\033[0m \n"
                <<"   2.\033[34m Mago de Gelo \033[0m \n"
                <<"   3.\033[32m Mago da Terra \033[0m "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m   Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital=70, mag=60, forca=50, def=50, ouro=50; // atributos inicias do personagem //
                    mago = "\033[31mMago de Fogo\033[0m";
                    historico += "\n   Sua escolha inicial foi ser uma Mago de Fogo";
                } 
                else if (escolha == 2) {
                    vital=80, mag=70, forca=40, def=40, ouro=50; // atributos inicias do personagem //
                    mago = "\033[34mMago de Gelo\033[0m";
                    historico += "\n   Sua escolha inicial foi ser uma Mago de Gelo";
                }
                else if (escolha == 3) {  
                    vital=90, mag=50, forca=50, def=40, ouro=50; // atributos inicias do personagem //
                    mago = "\033[32mMago da Terra\033[0m";
                    historico += "\n   Sua escolha inicial foi ser uma Mago da Terra";
                } 
                else {
                    cout<<"\033[31m   Esse Mago não existe! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
                   
           // ............................................................................................................................................................ //
           
                    // feito para guardar os atributos da escolha de mago e calcular quando curar atributos por meio da mecânica de repousar //
            vitalInicial=vital, magInicial=mag, forcaInicial=forca, defInicial=def;
                
            // ............................................................................................................................................................ //
            
                                    //Atualização de atributos//
            cout<<"\n   E aqui está sua ficha de atributos iniciais\n\n";
            cout<<"\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<endl;
                
                                        //2ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<<"\n Escolha a vestimenta que deseja se equipar antes de começar a aventura?"<<endl;
            cout<<"   1. Vestimenta Elemental \n"
                <<"   2. Vestimenta Espectral \n" 
                <<"   3. Vestimenta Bruta "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m   Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    bvital=10, bmag=5, bforca=0, bdef=5, pot=2; // atributos complementares da vestimenta //
                    cout<<"\n   Vestimenta Elemental: \n"
                        <<"   Cajado Hibrido (Magia +5), Túnica Estrelar (Vitalidade +10, Defesa +5), Poções (+2 - Cura +10) : "<<endl;
                    historico += " com uma Vestimenta Elemental.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    bvital=5, bmag=10, bforca=0, bdef=5, pot=2;// atributos complementares da vestimenta //
                    cout<<"\n   Vestimenta Espectral: \n"
                        <<"   Cajado Espectral (Magia +10), Túnica Obscura (Vitalidade +5, Defesa +5), Poções (+2 - Cura +10) : "<<endl;
                    historico += " com uma Vestimenta Espectral.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 3) {
                    bvital=10, bmag=8, bforca=5, bdef=1, pot=2;// atributos complementares da vestimenta //
                    cout<<"\n   Vestimenta Bruta: \n"
                        <<"   Cajado de Ferro (Magia +8, Força +5), Túnica Esfarrada (Vitalidade +10, Defesa +1), Poções (+2 - Cura +10) : "<<endl;
                    historico += " com uma Vestimenta Bruta.";
                    cin.ignore(), cin.ignore();
                }
                else {
                    cout<< "\033[31m    Essa Vestimenta não existe! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
                    
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n   Você está pronto para a sua aventura"<<endl;
            cout<<"\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //3ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<<"\n   Seguindo em frente na sua jornada após sair da escola de magos você busca se aventurar na floresta proibida. Após uma breve caminhada uma bifurcação inusitada surge na sua visão."<<endl;
            cout<<"      1. Passar pelo local com árvores levando as sombras da floresta em lodo   : "<<endl;
            cout<<"      2. Passar por uma pequena ponte, porém com o caminho cheio de vinhas  : "<<endl;
            cout<<"      3. Entrar na clareira cercado por tocos de árvores : "<<endl;
            
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital -= 10;
                    cout<< "\n   Resultado 1: \n"
                        <<"   Dificuldade em sair do lodo até uma área segura (Vitalidade -10)" << endl;
                    historico += "\n   Na bifurcação teve dificuldade no lodo da floresta proibida.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    vital -= 5, ouro -= 20;
                    cout<< "\n   Resultado 2: \n"
                        <<"   Se prendeu nas vinhas da ponte e perdeu parte do ouro no riacho (Vitalidade -5, Ouro -20)" << endl;
                    historico += "\n   Na bifurcação se prendeu nas vinhas e perdeu ouro na floresta proibida.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 3) {
                    vital -= 5, def -= 5;
                    cout<<"\n   Resultado 3: \n"
                        <<"   Algumas abelhas gigantes surgem e começam a te perseguir até o fim da trilha  (Vitalidade -5, Defesa -5)" << endl;
                    historico += "\n   Na bifurcação abelhas o cercaram, mas logo conseguiu fugir delas na floresta proibida.";
                    cin.ignore(), cin.ignore();
                } 
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //4ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<<"\n   Goblins o cercam vendo sua fragilidade...\n"
                <<"   Se prepare para batalhar. Faça sua escolha."<<endl;
            cout<<"      1. Usar uma magia  : \n"
                <<"      2. Utilizar seu cajado em força bruta  : \n"
                <<"      3. Apenas se defender e contra-atacar com rajadas de vento : "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital-=10, mag-=10, def-=10;
                    cout<<"\n   Resultado 1: Ataque mal sucedido. Pouco espaço entre as árvores. Perigoso o uso. Você providencia uma magia simples para derrotar os frageis goblins.\n"
                        <<"   (Vitalidade -10, Magia -10, Defesa -10 ) : "<<endl;
                    historico += "\n   Antes de continuar a jornada na floresta, Goblins o emboscaram. Você rapidamente tentou uma magia elemental sem sucesso e fez uma simples para derrotar os frageis goblins.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    vital-=5, forca-=10, def-=5;
                    cout<<"\n   Resultado 2: Goblins frageis \n"
                        <<"   (Vitalidade -5, Força -10, Defesa -5 ) : "<<endl;
                    historico += "\n   Antes de continuar a jornada na floresta, Goblins o embuscaram. Você rapidamente golpeou os goblins com o cajado para derrota-los.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 3) {
                    vital-=10, mag-=5, forca-=5;
                    cout<<"\n   Resultado 3: Pouco eficiente a magia de vento o obrigando a usar força bruta \n"
                        <<"   (Vitalidade -10, Magia -5, Força -5 ) : "<<endl;
                    historico += "\n   Antes de continuar a jornada na floresta, Goblins o embuscaram. Você tentou magia de vento sem sucesso e precisou golpear eles com o cajado para derrota-los.";
                    cin.ignore(), cin.ignore();
                }
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //5ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<<"\n   Ao fim da floresta uma entrada de caverna entalhada com arquitetura e runas antigas surge na sua frente. Você resolve explorar ela e sente que não era uma simples caverna, mas um vulcão adormecido."<<endl;
            cout<<"      1. Continuar e batalhar com os elementais de fogo a sua frente : \n"
                <<"      2. Continuar mas contornar para batalhar contra os esqueletos : \n"
                <<"      3. Se guiar pelos trilhos antigos e confrontar qualquer inimigo no caminho : "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital-=5, mag-=10, forca-=5;
                    cout<<"\n   Resultado 1: Os elementais demandaram uso de suas habilidades mágicas através do cajado \n"
                        <<"   (Vitalidade -5, Magia -10, Força -5)"<<endl;
                    historico += "\n   A frente você se depara e entra em uma caverna entalhada com arquitetura antiga, que se mostrou ser um vulcão. Batalha contra elementais de fogo para seguir a diante.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    mag-=5, forca-=10, ouro+=10;
                    cout<<"\n   Resultado 2: A resistência do corpo dos esqueletos era fraco. E por sorte alguns tinham moedas nos trapos de roupa.\n"
                        <<"   (Magia -5, Força -10, Ouro +10)"<<endl;
                    historico += "\n   A frente você se depara e entra em uma caverna entalhada com arquitetura antiga, que se mostrou ser um vulcão. Batalha contra esqueletos frágeis para seguir a diante.";
                    cin.ignore(), cin.ignore();
                }
                else if (escolha == 3) {
                    vital-=5, mag-=5, def-=10;
                    cout<<"\n   Resultado 3: Nenhum inimigo cruzou o seu caminho, mas houve um desmoronamente de pedras que precisou de uma proteção rápida para evitar maiores danos.\n"
                        <<"   (Vitalidade -5, Magia -5, Defesa -10)"<<endl;
                    historico += "\n   A frente você se depara e entra em uma caverna entalhada com arquitetura antiga, que se mostrou ser um vulcão. Seguiu os trilhos e precisou se proteger de um desmoronamento de pedras.";
                    cin.ignore(), cin.ignore();
                } 
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
                    
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
            // __________________________________________________________________________________________________________________________//
            
                                                    // momento para utilizar uma rolagem de dado //
            
            
            cout<< "\n   Um ser miterioso surge na sua presença com um sorriso malicioso. A criatura se vestia como um bufão com uma vestimenta colorida. Um tom irritante nas expressões e fala\n"
                <<"\033[034m    - Antes que avançe para mais dentro da caverna, acho interessante medir sua sorte antes que perca um braço desnecessariamente... ou necessariamente\033[0m\n"
                <<"   O bufão tira do bolso um dado dourado e arremesa ao alto, quase longe de vista. A cada peco milesegundo que o dado buscava o chão ele aumentava até surgir um dado de um metro no chão com um resultado que poderia definir a jornada do mago"<<endl;
            srand(time(NULL)); // semente randômica gerada a partir da hora do sistema
            for(i=0;i<1;i++){
                dado=(rand() % 6) + 1; // o % coloca os números gerados entre 0 e o resto da divisão - 1
                cout<<"\n      E o resultado foi : \033[33m"<<dado<<"       \033[0m\n";
            }
            cout<<"\033[034m    - Temos o resultado. Aperte qualquer coisa e veja o que aconteceu. Vai! Vai! Coragem! \033[0m\n";
            cin.ignore();
                                    
            if (dado == 1) {
                cout<<"\033[034m    - Sortudo. Nada acontece com um resultado mixuruco desse. \033[0m\n";
                cout<<"\n\033[034m    - Aproveite a batalha contra a criatura chefe desse vulcão. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 2) {
                vital -= 10;
                cout<<"   Vitalidade reduzida \n";
                cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<endl;
                cout<<"\n\033[034m    - Aproveite a batalha contra a criatura chefe desse vulcão. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 3){
                cout<<"\033[034m    - Sortudo. Nada acontece com um resultado mixuruco desse. \033[0m\n";
                cout<<"\n\033[034m    - Aproveite a batalha contra a criatura chefe desse vulcão. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 4){
                pot +=1;
                cout<<"   Você ganhou uma poção \n";
                cout<<"\033[32m   Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                cout<<"\n\033[034m    - Aproveite a batalha contra a criatura chefe desse vulcão. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 5) {
                forca += 10;
                cout<<"   Força aumentada \n";
                cout<<"\033[32m   Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\033[0m"<<endl;
                cout<<"\n\033[034m    - Aproveite a batalha contra a criatura chefe desse vulcão. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 6){
                cout<<"\033[034m    - Você vai realmente perder um braço se continuar. Acabamos o jogo por aqui. Boa sorte (ou não) na próxima. \033[0m\n";
                historico += "\n   Quando finalmente o desafio surgi a sua vista, uma figura estranha vestida de bufão cruza o seu caminho e joga um dado misterioso. \033[31mE o destino foi morte!.\033[0 ";
                historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                jogoFeito = true;
                cin.ignore();
                cout << "\033c";
                break; // retorna menu //
            }
            
            historico += "\n   Quando finalmente o desafio surgi a sua vista, uma figura estranha vestida de bufão cruza o seu caminho e joga um dado misterioso. Ele anuncia o resultado, mas você não entende o que aconteceu e apenas seguiu adiante.";
            
            cout << "\033c";
            
            // __________________________________________________________________________________________________________________________//
            
            
            // ............................................................................................................................................................ //
            
                                                                        // BATALHA CONTRA O IFRIT //
                                                                //6ª, 7ª, 8ª, 9ª e 10ª Escolha do jogo//
                                                                
            // Checkpoint de atributos - reseta status caso morra dentro da Batalha contra o Ifrit //
            vitalCheckpoint = vital, magCheckpoint = mag, forcaCheckpoint = forca, defCheckpoint = def, ouroCheckpoint = ouro, potCheckpoint = pot;
            bvitalCheckpoint = bvital, bmagCheckpoint = bmag, bforcaCheckpoint = bforca, bdefCheckpoint = bdef;
            
            while (desafio && mortes < 3) {
                
                fimDeJogo = false; // para sair do loop após as 3 mortes - verificar se realmente morreu para voltar menu //
                
                // Aqui fica o controlador de vidas e contagem de mortes para resetar a batalha do Ifrit e/ou acabar sessão //
                                /////////////////////////////////////////////////////////////////        
                if ((vital+bvital) <= 0) {
                    if (desafio) {
                        mortes++; // soma mais uma morte //
                        if (mortes >= 3) {
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            cout<<"\n\033[31m             VOCÊ FOI DERROTADO DEFINITIVAMENTE!      \033[0m\n";
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            historico += "\n   Seu desafio foi o poderoso demônio do fogo \033[31mIfrit\033[0m. A batalha foi ardua, mas infelizmente você foi \033[31mDerrotado\033[0m!.";
                            historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                            cin.ignore(), cin.ignore();
                            desafio = false;
                            fimDeJogo = true;
                            jogoFeito = true;
                            cout << "\033c";
                            break; // retorna menu //
                        }
                    }
                        
                    cout<<"\n\033[31m                         Você foi derrotado...                           ";
                    cout<<"\n                O tempo retrocede e você volta ao seu último checkpoint!\033[0m\n";
                    cin.ignore(), cin.ignore();
                    // restaura atributos
                    vital = vitalCheckpoint, mag = magCheckpoint, forca = forcaCheckpoint, def = defCheckpoint, ouro = ouroCheckpoint, pot = potCheckpoint;
                    bvital = bvitalCheckpoint, bmag = bmagCheckpoint, bforca = bforcaCheckpoint, bdef = bdefCheckpoint;
                    bdef_pro = 0;
                    cenaAtual = 1;
                    cout << "\033c";
                }
                // Condição de "exaustão mágica" (magia zerada) //
                else if ((mag + bmag) <= 0) {
                    if (desafio) {
                        mortes++;
                        if (mortes >= 3) {
                            cout << "\n\033[35m======================================================\033[0m\n";
                            cout << "\n\033[35m       SUA ENERGIA MÁGICA FOI TOTALMENTE ESGOTADA!    \033[0m\n";
                            cout << "\n\033[35m======================================================\033[0m\n";
                            historico += "\n   Durante o confronto com \033[31mIfrit\033[0m, sua magia se extinguiu por completo, e você foi consumido pelas chamas etéreas e foi \033[31mDerrotado\033[0.";
                            historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                            cin.ignore(), cin.ignore();
                            desafio = false;
                            fimDeJogo = true;
                            jogoFeito = true;
                            cout << "\033c";
                            break; // retorna menu //
                        }
                    }
                    
                    cout << "\n\033[35m                    Sua energia mágica se esgotou...                      ";
                    cout << "\n           A exaustão o domina, e o tempo retrocede ao último checkpoint.\033[0m\n";
                    cin.ignore(), cin.ignore();
                    // restaura atributos (checkpoint)
                    vital = vitalCheckpoint, mag = magCheckpoint, forca = forcaCheckpoint, def = defCheckpoint, ouro = ouroCheckpoint, pot = potCheckpoint;
                    bvital = bvitalCheckpoint, bmag = bmagCheckpoint, bforca = bforcaCheckpoint, bdef = bdefCheckpoint;
                    bdef_pro = 0;
                    cenaAtual = 1;
                    cout << "\033c";
                }
                                /////////////////////////////////////////////////////////////////
                          
                switch (cenaAtual) {
                    
                // ===== Batalha turno 1 =====
                case 1: {
                
                    cout<<"\n\033[31m  ============================================================================================================  \033[0m\n";
                    cout<<"\n\033[31m                A GRANDE BATALHA CHEGOU - A BUSCA PELO CRISTAL DA BESTA DE FOGO IFRIT\033[0m\n"; 
                    cout<<"\n\033[31m  ============================================================================================================  \033[0m\n";
                    
                    // Mostra as vidas restantes em formato de corações
                    vidasRestantes = 3 - mortes;
                    cout<<"\n\033[32m   Vidas :   \033[0m";
                    for (int i = 0; i < vidasRestantes; i++) {
                        cout<< " ❤️ ";
                    }
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                    
                    cout<<"\n\033[31m  ============================================================================================================  \033[0m\n";
                    
                                                    // 1ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                                
                    
                    cout<<"\nFinalmente chegamos ao seu primeiro grande desafio. Ao fim desse vulcão existe uma besta sedenta para quebrar as runas que a aprisionam e poder fugir do vulcão."<<endl;
                    cout<<"A besta olha para você com um sorriso vitorioso quebrando suas algemas de runas anunciando para desafiar você."<<endl;
                    cout<<"\033[031m - COMO OUSA VIR A MINHA PRESENÇA. PREPARE-SE PARA ENFRENTAR A FÚRIA DE IFRIT \033[0m"<<endl;
                    cout<<"   1. Você escolhe atacar a distância com sua magia elemental : \n"
                        <<"   2. Apenas lançar uma"<<"\033[34m"<<" magia de proteção"<<"\033[0m"<<" para aguentar o primeiro ataque de\033[031m Ifrit\033[0m : \n"
                        <<"   3. Espera o ataque acontecer e tenta descipar o fogo dele com a sua magia ao mesmo tempo: "<<endl;
                    
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    do {
                        cout<<"\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha; 
                        if (escolha == 1) {
                            vital-=10, mag-=5, def-=10, bvital=0, bdef=0;
                            cout<<"\n   Resultado 1: Seu ataque foi suprimido por uma explosão inicial de fogo. Sua túnica perde o efeito"<<endl;
                            cout<<"   (Vitalidade -10, Magia -5, Defesa -10, Você perde o bônus da túnica)"<<endl;
                        } 
                        else if (escolha == 2) {
                            vital-=5, mag-=5, def-=10, bdef_pro+=5, bvital=0, bdef=0;
                            cout<<"\n   Resultado 2: Você suporta o primeiro ataque explosivo, mas não suficiente para proteger a magia da sua túnica "<<endl;
                            cout<<"   (Vitalidade -5, Magia -5, Defesa -10, Proteção Defesa +5, Você perde o bônus da túnica)"<<endl;
                        } 
                        else if (escolha == 3) {
                            vital-=10, def-=10, bvital=0, bdef=0;
                            cout<<"\n   Resultado 3: A besta suprimiu por muito tempo essa explosão inicial e você não teve tempo de reação para medir força com ele. Túnica rasgada" << endl;
                            cout<<"   (Vitalidade -10, Defesa -10, Você perde o bônus da túnica)"<<endl;
                        }
                        else {
                            cout<< "\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                        }
                    } while (escolha < 1 || escolha > 3);
                                /////////////////////////////////////////////////////////////////  
                                
                                    //Atualização de atributos//  
                    if (bdef_pro >= 5) {                
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                        cout<<"\033[31m   Túnica rasgada : perdeu o efeito \033[0m"<<endl;
                    } 
                    else {
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                        cout<<"\033[31m   Túnica rasgada : perdeu o efeito \033[0m"<<endl;
                    }
                    
                    cenaAtual = 2;
                    break;
                } // fim do case 1 do switch cenadas do desafio //
                
                // ===== Batalha turno 2 =====
                case 2: {
                
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore(), cin.ignore();
                    cout<<"\n\033[31m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 2ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                          
                    cout<<"\nA batalha se intensifica e os golpes começam a fazer cada vez menos efeito perante a criatura que gargalha com desdém."<<endl;
                    cout<<"\033[031m - VOCÊ REALMENTE IMAGINAVA COM ESSE PODER LIMITADO PODERIA ME ENFRENTAR E AINDA POR CIMA ME DERROTAR? PATETICO\033[0m"<<endl;
                    cout<<"Nesse momento de fraqueza havia apenas uma escolha: invocar um espirito elemental com magia enquanto recupera a vida perdida"<<endl;
                    cout<<"   1. Você invoca o espirito elemental e ajuda com o resto de magia que tem na luta : \n"
                        <<"   2. Você invoca o espirito elemental e lança uma \033[34mmagia de proteção\033[0m em si para reforçar a defesa enquanto pensa em um plano : \n"
                        <<"   3. Você invoca o espirito elemental e reforça ele com sua magia : "<<endl;
                    
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    do {
                        cout<<"\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha; 
                        if (escolha == 1) {
                            vital-=10, mag-=25, forca-=5;
                            cout<<"\n   Resultado 1: Seu espirito ataca ferozmente a besta de fogo e tenta te proteger enquanto você ataca com magia através do cajado"<<endl;
                            cout<<"   (Vitalidade -10, Magia -5, Força -5)"<<endl;
                        } 
                        else if (escolha == 2) {
                            vital-=10, mag-=30, forca-=10, bdef_pro+=5;
                            cout<<"\n   Resultado 2: Seu espirito ataca ferozmente a besta de fogo enquanto você lança uma proteção em si ficando escondido entre as pedras vulcanicas."<<endl;
                            cout<<"   (Vitalidade -10, Magia -10, Força -10, Proteção Defesa +5)"<<endl;
                        }
                        else if (escolha == 3) {
                            vital-=10, mag-=30, forca-=5;
                            cout<<"\n   Resultado 3: Seu espirito ataca ferozmente a besta de fogo enquanto reforça seu poder com magia elemental."<<endl;
                            cout<<"   (Vitalidade -10, Magia -10, Força -5)"<<endl;
                        }
                        else {
                            cout<< "\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                        }
                    } while (escolha < 1 || escolha > 3);
                                /////////////////////////////////////////////////////////////////  
                                
                                    //Atualização de atributos//  
                    if (bdef_pro >= 5) {                
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    } 
                    else {
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    }
                    
                    cenaAtual = 3;
                    break;
                } // fim do case 2 do switch cenadas do desafio //
                
                // ===== Batalha turno 3 =====
                case 3: {
                
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore(), cin.ignore();
                    cout<<"\n\033[31m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 3ª Escolha da batalha //
                                ///////////////////////////////////////////////////////////////// 
                                
                    cout<<"\nO espirito elemental invocado está conseguindo suprimir muitos ataques de \033[031m Ifrit\033[0m. Agora você tem uma decisão crucial"<<endl;            
                    // Condicionais: só mostra as opções liberadas //
                    if ((vital+bvital) <= 35) {
                        opcao1="\033[31m   1 Urgência.\033[0m Use as poções senão sua jornada acabará em breve :\n";
                    }
                    else {
                        opcao1="   1. Você usa as poções e recupera o fôlego atrás de uma pedra usando magia :\n";
                    }
                    if ((def+bdef+bdef_pro) <= 15) {
                        opcao2="\033[31m   2 Urgência.\033[0m Sua defesa está baixa. Você repousa para recuperar o fôlego, mas os próximos ataques podem ser fatais :\n";
                    }
                    else {
                        opcao2="   2. Você economiza magia e recupera o fôlego para o próximo ataque :\n";
                    } 
                    if ((mag+bmag) <= 30) {
                        opcao3="\033[31m   3 Urgência.\033[0m Baixa magia. Canalize as poções para converter em magia :\n";
                    }
                    else {
                        opcao3="   3. Sem alternativas você canaliza as poções convertendo em magia para atacar a besta junto com o espirito elemental  :\n";
                    }   
                    
                    cout<<opcao1; 
                    cout<<opcao2;
                    cout<<opcao3;
                    
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    do {
                        cout<<"\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha; 
                        if (escolha == 1) {
                            vital+=20, pot-=pot;
                            vital-=10;
                            cout<<"\n   Resultado 1: Você recupera vitalidade e seu espirito elemental é derrotado \n"
                                <<"   (Vitalidade +20 porém o ataque tira Vitalidade -10 - Poções 0)"<<endl;
                        } 
                        else if (escolha == 2) {
                            vital-=5;
                            cout<<"\n   Resultado 2: Você está se recuperando, mas seu espirito elemental é derrotado \n"
                                <<"   (Vitalidade -5)"<<endl;
                        }
                        else if (escolha == 3) {
                            vital-=5, pot-=pot, mag+=10;
                            cout<<"\n   Resultado 3: Você recupera parte de sua magia e seu espirito elemental é derrotado \n"
                                <<"   (Vitalidade -5, Magia +10 - Poções 0)"<<endl;
                        }
                        else {
                            cout<< "\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                        }
                    } while (escolha < 1 || escolha > 3);
                                /////////////////////////////////////////////////////////////////  
                                
                                    //Atualização de atributos//  
                    if (bdef_pro >= 5) {                
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    } 
                    else {
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    }
                    
                    cenaAtual = 4;
                    break;
                } // fim do case 3 do switch cenadas do desafio //
                
                // ===== Batalha turno 4 =====
                case 4: {
                
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore(), cin.ignore();
                    cout<<"\n\033[31m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 4ª Escolha da batalha //
                                ///////////////////////////////////////////////////////////////// 
                                
                    cout<<"\nA batalha se intensifica após o descanso. Sem o espirito elemental você precisa tomar suas decisões rapida e certeiramente.\033[031m Ifrit\033[0m cansado abriu uma brecha para poder ataca-lo"<<endl;            
                    cout<<"   1. Realizar um ataca frontal fisico com o bastão economizando magia com uma simples de lufada de vento : \n"
                        <<"   2. Canalziar sua magia e realizar uma ataque único de poder elemental : \n";
                    // Condicionais: só mostra as opções liberadas //
                    if (pot >= 2) {
                        opcao3="\033[31m   3 Urgência.\033[0m Use as poções senão sua jornada acabará em breve:\n";
                    }
                    else {
                        opcao3="   3. Ignorando sua situação fisica e de mana você parte para um ataque lateral utilizando as rochas para prender a besta :\n";
                    }
                    cout<<opcao3; 
                    
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    do {
                        cout<<"\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha; 
                        if (escolha == 1) {
                            forca-=10;
                            cout<<"\n   Resultado 1: O ataque parece ter surtido efeito deixando\033[031m Ifrit\033[0m tonto  \n"
                                <<"   (Força -10)"<<endl;
                        } 
                        else if (escolha == 2) {
                            mag-=20;
                            cout<<"\n   Resultado 2: Uma grande quantidade de magia resoa através do seu cajado acertando a fera, mas não sabe se foi suficiente \n"
                                <<"   (Magia -20)"<<endl;
                        }
                        else if (escolha == 3) {
                            if (pot >=2) {
                                vital+=20, pot-=pot;
                                cout<<"\n   Resultado 3: Você recupera parte da vitalidade antes da escolha decisiva \n"
                                    <<"   (Vitalidade +20 - Poções 0)"<<endl;
                            }
                            else {
                                mag-=15;
                                cout<<"\n   Resultado 3: Você utiliza grande parte da sua magia para prender a besta, mas não sabe se foi suficiente \n"
                                    <<"   (Magia -15)"<<endl;
                            }
                        }
                        else {
                            cout<< "\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                        }
                    } while (escolha < 1 || escolha > 3);
                                /////////////////////////////////////////////////////////////////  
                                
                                    //Atualização de atributos//  
                    if (bdef_pro >= 5) {                
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    } 
                    else {
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    }   
                        
                    cenaAtual = 5;
                    break;
                } // fim do case 4 do switch cenadas do desafio //
                
                // ===== Batalha turno 5 =====
                case 5: {
                    
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore(), cin.ignore();
                    cout<<"\n\033[31m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 5ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                          
                    cout<<"\nSeu companion está conseguindo suprimir os ataques de fogo de\033[031m Ifrit\033[0m que se encontra exausto. Tanto ele quanto você partem para um ataque final."<<endl;
                    cout<<"   1. Drenar um pouco da magia que cerca os totens do vulcão para sobrevir ao ataque final de\033[031m Ifrit\033[0m e finalizar o duelo.\n"
                        <<"   2. Ampliar a força com o resto vitalidade que resta e se defender da explosão final do poder de\033[031m Ifrit\033[0m.\n"
                        <<"   3. Um último sopro de magia de vento canalizando a gota final de determinação : "<<endl;
                    
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    do {
                        cout<<"\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha; 
                        if (escolha == 1) {
                            vital-=10, mag-=5;
                            cout<<"\n   Resultado 1: Você aguenta o ataque e finalmente\033[031m Ifrit\033[0m foi derrotado e agora obtem ele em formato de cristal para a sua coleção mágica."
                                <<"   (Vitalidade -10, Magia -5)"<<endl;
                        } 
                        else if (escolha == 2) {
                            vital-=15, mag-=5, forca-=10;
                            cout<<"\n   Resultado 2: Você se expôs para o ataquer ser eficiente, mas aguenta e finalmente\033[031m Ifrit\033[0m foi derrotado e agora obtem ele em formato de cristal para a sua coleção mágica."
                                <<"   (Vitalidade -15, Magia -5, Força -10)"<<endl;
                        } 
                        else if (escolha == 3) {
                            mag-=5, forca-=5;
                            cout<<"\n   Resultado 3: \033[031m Ifrit\033[0m ficou tão debilitado no último ataque que não fez esforço para ceder a magia de vento. Agora você obteu ele em formato de cristal para a sua coleção mágica."
                                <<"   (Magia -5, Força -5)"<<endl;
                        }
                        else {
                            cout<< "\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                        }
                    } while (escolha < 1 || escolha > 3);
                                /////////////////////////////////////////////////////////////////  
                                
                                    //Atualização de atributos//  
                    if (bdef_pro >= 5) {                
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    } 
                    else {
                        cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                        cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                            <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                            <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;        
                    }      
                        
                    if ((vital+bvital) > 0 && (mag + bmag) > 0) {
                        cenaAtual = -1; 
                    } // fim //
                    break;
                } // fim do case 5 do switch cenadas do desafio //
                    default:
                    desafio = false;
                    jogoAtivo = false;
                    break;
                } // fecha switch cenas do desafio //
            } // fim do while do desafio do chefe //
            
            desafio = true, jogoAtivo = true, mortes = 0, cenaAtual = 1;
            
            if (fimDeJogo) {
                break; // encerra o case 1 (volta ao menu)
            }
        
            cout<<"\n\033[33m   //////////////////////////////////////////////////////////////////////\033[0m"<<endl;
            cout<<"\n\033[33m                       !!!LEVEL UP!!!\033[0m"<<endl;
            cout<<"\033[33m               !!!+10 em todos os atributos de combate!!!\033[0m"<<endl;
            cout<<"\033[33m   !!!Ainda é necessário repousar ou curar para ganhar os atributos!!!\033[0m"<<endl;
            cout<<"\n\033[33m   //////////////////////////////////////////////////////////////////////\033[0m"<<endl;
            historico += "\n   Seu desafio no vulcão foi o poderoso demônio do fogo \033[31mIfrit\033[0m. A batalha foi ardua e após muita persistência você saiu \033[32mVitorioso\033[0m.";
            cin.ignore(), cin.ignore();
            
            // ............................................................................................................................................................ //
            
                        // Ajustando atributo totais do personagem - !!!LEVEL UP!!!//
            vitalInicial = vitalInicial+10, magInicial = magInicial+10, forcaInicial = forcaInicial+10, defInicial=defInicial+10; // Mago // 
            
            // ............................................................................................................................................................ //
            
                                    // Continuando a jornada //
                                    
            cout << "\033c";
                                    //Atualização de atributos// 
            if (bdef_pro >= 5) {                
                cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                    <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                    <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;        
            } 
            else {
                cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                    <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                    <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;        
            }    
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
            // __________________________________________________________________________________________________________________________//
            
                                                    // momento para utilizar uma rolagem de dado //
            
            
            cout<< "\n   No momento de fraqueza após a batalha o Bufão resurge. Você ignora ele e sai do vulcão, mas o Bufão persiste. \n"
                <<"\033[034m    -  Você está tão fraco que um sopro te derruba. Claro, se eu usar esse pedaço de madeira aqui do lado acho que você bate as botas. Logo vamos tentar mais uma vez a sorte.\033[0m\n"
                <<"   O bufão tira do bolso novamente o dado dourado e arremesa ao alto, quase longe de vista. A cada peco milesegundo que o dado buscava o chão ele aumentava até surgir um dado de um metro no chão com um resultado que poderia definir a jornada do mago"<<endl;
            srand(time(NULL)); // semente randômica gerada a partir da hora do sistema
            for(i=0;i<1;i++){
                dado=(rand() % 6) + 1; // o % coloca os números gerados entre 0 e o resto da divisão - 1
                cout<<"\n      E o resultado foi : \033[33m"<<dado<<"       \033[0m\n";
            }
            cout<<"\033[034m    - Temos o resultado. Aperte qualquer coisa e veja o que aconteceu. Vai! Vai! Coragem! Você está fraco demais para ignorar o meu pedido. \033[0m\n";
            cin.ignore();
                                    
            if (dado == 1) {
                cout<<"\033[034m    - Sortudo. Nada acontece com um resultado mixuruco desse... Novamente. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 2) {
                vital = vital / 2;
                cout<<"\033[034m    - Antes era perda de vitalidade aqui, mas eu já sei o que vem nas próximas escolhas então deixamos para um outro momento. \033[0m\n";
                cin.ignore();
                cout<<"\033[034m    - Mas pensando bem vou deixar a sua vida bem baixa. \033[0m\n";
                vital=1;
                cout<<"\033[32m   Vitalidade : \033[0m\033[31m"<<vital<<"\033[0m\033[33m"<<"+"<<bvital<<"\033[0m"<<endl;
                cin.ignore();
            }
            else if (dado == 3){
                cout<<"\033[034m    - Ignore. Odeio o número 3. Fazer três escolhas é tão chato e blá blá blá. \033[0m\n";
                cin.ignore();
            }
            else if (dado == 4){
                cout<<"\033[034m    - Você não tem mais sanidade para continuar. Acabamos o jogo por aqui. Boa sorte (ou não) na próxima. \033[0m\n";
                historico += "\n   O bufão volta a surgir a sua frente mesmo debiltado pela batalha contra a besta de fogo. Ele não se importa e apenas ceifa sua vida nesse momento. Ele não gostou da sua jornada e deixou o dado decidir por ele. \033[31mLogo o seu destino foi a morte!.\033[0 ";
                historico += "\n\033[32m  ============================================================================================================  \033[0m\n";
                cin.ignore();
                jogoFeito = true;
                cout << "\033c";
                break; // retorna menu //
            }
            else if (dado == 5) {
                forca += 10;
                cout<<"   Força aumentada. Só porque sim. \n";
                cout<<"\033[32m   Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\033[0m"<<endl;
                cin.ignore();
            }
            else if (dado == 6){
                pot +=1;
                cout<<"   Você ganhou uma poção \n";
                cout<<"\033[32m   Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                cin.ignore();
            }
            
            historico += "\n   O bufão volta a surgir a sua frente mesmo debiltado pela batalha contra a besta de fogo. Ele anuncia o resultado, mas você novamente não entende o que aconteceu e apenas seguiu adiante.";
            
            cout << "\033c";
            
            // __________________________________________________________________________________________________________________________//
            
            cout << "\033c";
                                    //Atualização de atributos// 
            if (bdef_pro >= 5) {                
                cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                    <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m+"<<bdef<<"\033[0m"<<"\033[34m+"<<bdef_pro<<"\033[0m"<<"\t"
                    <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;        
            } 
            else {
                cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                    <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                    <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;        
            }    
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //11ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n   Após a longa jornada na floresta e enfrentar o demônio do fogo\033[031m Ifrit\033[0m, você chega a uma estalagem de beira de estrada para descansar."<<endl;
            cout<<"      1. Descansar rapidamente - Seu ouro \033[32m"<<ouro<<" menos "<<ouro*0.30<<"\033[0m"<<" (recupera 50% dos atributos) : \n"
                <<"      2. Descansar com mais tempo - Seu ouro \033[32m"<<ouro<<" menos "<<ouro*0.40<<"\033[0m"<<" (recupera 60% dos atributos) :\n"
                <<"      3. Descansar completamente - Seu ouro \033[32m"<<ouro<<" menos "<<ouro*0.50<<"\033[0m"<<" (recupera 75% dos atributos) :"<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital = vitalInicial/2, mag = magInicial/2, forca = forcaInicial/2, def = defInicial/2;
                    ouro = ouro*0.3;
                    cout<<"\n   Resultado 1: Você retornou para 50% dos seus atributos : "<<endl;
                    historico += "\n   A jornada te leva a uma estalagem, fora da floresta e vulcão, e você decidiu recuperar 50% dos seus atributos.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    vital = vitalInicial*0.6, mag = magInicial*0.6, forca = forcaInicial*0.6, def = defInicial*0.6;
                    ouro = ouro*0.4;
                    cout<<"\n   Resultado 2: Você retornou para 60% dos seus atributos : "<<endl;
                    historico += "\n   A jornada te leva a uma estalagem, fora da floresta e vulcão, e você decidiu recuperar 60% dos seus atributos.";
                    cin.ignore(), cin.ignore();
                }
                else if (escolha == 3) {
                    vital = vitalInicial*0.75, mag = magInicial*0.75, forca = forcaInicial*0.75, def = defInicial*0.75;
                    ouro = ouro/2;
                    cout<<"\n   Resultado 3: Você retornou para 75% dos seus atributos : "<<endl;
                    historico += "\n   A jornada te leva a uma estalagem, fora da floresta e vulcão, e você decidiu recuperar 75% dos seus atributos.";
                    cin.ignore(), cin.ignore();
                } 
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
            
            bdef_pro=0;
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;    
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //12ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<<"\n   Saindo da estalagem você se depara com um estranho mercador com seu sorriso estranho no rosto, mas familiar, te chamando para fazer negocios."<<endl; 
            cout<<"   Ele aponta para a sua túnica rasgada e logo oferece novas vestimentas."<<endl;
            cout<<"      1. Vestimenta Radiante - consumirá "<<ouro<<" moedas do seu ouro : \n"
                <<"      2. Vestimenta Estelar - consumirá "<<ouro<<" moedas do seu ouro : \n"
                <<"      3. Vestimenta de Sangue - consumirá "<<ouro<<" moedas do seu ouro : "<<endl;
            
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<<"\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    bvital=10, bmag=10, bdef=10, ouro=0, pot=1;    
                    cout<<"\n    Vestimenta Radiante : \n" 
                        <<"   Cajado Reluzente (Magia +10), Túnica Dourada (Defesa +10, Vitalidade +10), Poções (+1 - Cura +10), Garrafa Mágica (+1) : "<<endl;
                    historico += "\n   Você encontra um mercador estranho e troca a sua roupa por uma Vestimenta Radiante.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    bvital=10, bmag=15, bdef=5, ouro=0, pot=1;  
                    cout<<"\n    Vestimenta Estelar: \n"
                        <<"   Cajado Cometa (Magia +15), Túnica Lunar (Defesa +5, Vitalidade +10), Poções (+1 - Cura +10), Garrafa Mágica (+1) : "<<endl;
                    historico += "\n   Você encontra um mercador estranho e troca a sua roupa por uma Vestimenta Estelar.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 3) {
                    bvital=15, bmag=15, bdef=5, ouro=0, pot=1;  
                    cout<<"\n    Vestimenta Estelar: \n"
                        <<"   Cajado Cometa (Magia +15), Túnica Bloodmoon (Defesa +5, Vitalidade +15), Poções (+1 - Cura +10), Garrafa Mágica (+1) : "<<endl;
                    historico += "\n   Você encontra um mercador estranho e troca a sua roupa por uma Vestimenta de Sangue.";
                    cin.ignore(), cin.ignore();
                }
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
                    
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;  
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //13ª Escolha do jogo//
                    ///////////////////////////////////////////////////////////////// 
                
            cout<< "\n   Após o descanso na estalagem e renovação de vesitmenta, você segue pela trilha que leva ao Vale das Cinzas.\n";
            cout<< "   O céu está coberto por nuvens vermelhas. As árvores estão queimadas e o ar é denso.\n";
            cout<< "   Uma sombra salta de trás de uma pedra e um \033[33mLobisomem Etéreo\033[0m, deformado pela energia mágica do vulcão.\n";
            cout<< "   Ele rosna e se aproxima.\n";
            cout<< "      1. Atacar com magia elemental.\n"
                << "      2. Defender-se e esperar o momento certo.\n"
                << "      3. Tentar purificar a criatura com a garrafa mágica."<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                
                switch (escolha) {
                    case 1:
                        mag -= 5; forca -= 5;
                        cout<< "\n   Resultado 1: Você lança uma rajada mista e o monstro ruge. Ele foge ferido, mas sua energia mágica diminui.\n";
                        cout<< "   (Magia -5, Força -5)\n";
                        historico += "\n   Lutou com um Lobisomem Etéreo e o derrotou usando magia elemental.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 2:
                        def -= 5; vital -= 5;
                        cout<< "\n   Resultado 2: Você ergue seu cajado e bloqueia os ataques até que a criatura se canse e recue.\n";
                        cout<< "   (Defesa -5, Vitalidade -5)\n";
                        historico += "\n   Resistiu ao Lobisomem Etéreo, mantendo a calma e vencendo pela paciência.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 3:
                        mag -= 3; vital -= 5;
                        cout<< "\n   Resultado 3: Você ergue a garrafa mágica e uma luz azul envolve a criatura. Ela desaparece em paz.\n";
                        cout<< "   (Vitalidade -5, Magia -3)\n";
                        historico += "\n   Usou a garrafa mágica para purificar a criatura corrompida.";
                        cin.ignore(), cin.ignore();
                        break;
                    default:
                        cout << "\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                }
            } while (escolha < 1 || escolha > 3);
            
            // ____________________________________________________________ //
            
            // Aqui vem a checagem de fim de jogo para a próximas decisões //
            if ((vital + bvital) <= 0) {
                cout<<"\n\033[31m   Sua vitalidade chegou a 0! Você caiu na jornada...\n";
                cout<<"   Fim de Jogo!\033[0m\n";
                historico += "\n   Infelizmente após a escolha e duelo sua vida chegou a 0 e não resistiu.\033[31m Derrota! \033[0m";
                historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                cin.ignore(), cin.ignore();
                jogoFeito = true;
                cout << "\033c";
                break; // retorna menu //
            }
            if ((mag + bmag) <= 0) {
                cout<<"\n\033[35m   Sua energia mágica se esgotou! Você caiu na jornada...\n";
                cout<<"   Fim de Jogo!\033[0m\n";
                historico += "\n   Infelizmente após a escolha e duelo sua energia esgotou e seu corpo não resistiu.\033[31m Derrota! \033[0m";
                historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                cin.ignore(), cin.ignore();
                jogoFeito = true;
                cout << "\033c";
                break; // retorna menu //
            }
            // ____________________________________________________________ //
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //14ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
                    
            cout<< "\n   Mais à frente, uma torre feita inteiramente de vidro surge entre as ruínas.\n";
            cout<< "   A estrutura parece pulsar com o mesmo brilho etéreo do cristal que você carrega.\n";
            cout<< "   Ao se aproximar, runas começam a acender sob seus pés.\n";
            cout<< "      1. Entrar na torre.\n"
                << "      2. Ignorar o local e seguir pelo desfiladeiro.\n"
                << "      3. Usar magia para tentar entender o que é o lugar."<<endl;
               
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                
                switch (escolha) {
                    case 1:
                        forca += 5; vital -= 5;
                        cout<< "\n   Resultado 1: Você entra e sente o ar pesar. Ecos de vozes antigas ecoam  e uma delas fala seu nome.\n";
                        cout<< "   (Força +5, Vitalidade -5)\n";
                        historico += "\n   Entrou na Torre de Vidro e ouviu vozes de antigos magos.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 2:
                        vital += 10;
                        cout<< "\n   Resultado 2: Você decide não arriscar e continua o caminho. O ar parece mais leve longe da torre.\n";
                        cout<< "   (Vitalidade +10)\n";
                        historico += "\n   Ignorou a Torre de Vidro, preferindo preservar sua energia.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 3:
                        mag -= 5; def += 10;
                        cout<< "\n   Resultado 3: Através da magia, você vê que a torre é um selo. Um portal para outro plano.\n";
                        cout<< "   (Magia -5, Defesa +10)\n";
                        historico += "\n   Decifrou o propósito da Torre de Vidro: um portal lacrado.";
                        cin.ignore(), cin.ignore();
                        break;
                    default:
                        cout<< "\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                }
            } while (escolha < 1 || escolha > 3);
            
            // ____________________________________________________________ //
            
            // Aqui vem a checagem de fim de jogo para a próximas decisões //
            if ((vital + bvital) <= 0 || (mag + bmag) <= 0) {
                cout<< "\n\033[31m   O poder da torre consome suas forças...\n   Fim de Jogo!\033[0m\n";
                historico += "\n   Morreu nas ruínas da Torre de Vidro.\033[31m Derrota! \033[0m";
                historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                cin.ignore(), cin.ignore();
                jogoFeito = true;
                cout << "\033c";
                break; // retorna menu //
            }
            // ____________________________________________________________ //
            
            cout << "\033c";
            
            // __________________________________________________________________________________________________________________________//
            
            // ............................................................................................................................................................ //
            
                                                                        // BATALHA CONTRA O BUFÃO //
                                                                //15ª, ROLAGEM DE DADO, 16ª e 17ª Escolha do jogo//
                                                                
            // Checkpoint de atributos - reseta status caso morra dentro da Batalha contra o Ifrit //
            vitalCheckpoint = vital, magCheckpoint = mag, forcaCheckpoint = forca, defCheckpoint = def, ouroCheckpoint = ouro, potCheckpoint = pot;
            bvitalCheckpoint = bvital, bmagCheckpoint = bmag, bforcaCheckpoint = bforca, bdefCheckpoint = bdef;
            
            while (desafio && mortes < 3) {
                
                fimDeJogo = false; // para sair do loop após as 3 mortes - verificar se realmente morreu para voltar menu //
                
                // Aqui fica o controlador de vidas e contagem de mortes para resetar a batalha do Ifrit e/ou acabar sessão //
                                /////////////////////////////////////////////////////////////////        
                if ((vital+bvital) <= 0) {
                    if (desafio) {
                        mortes++; // soma mais uma morte //
                        if (mortes >= 3) {
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            cout<<"\n\033[31m             VOCÊ FOI DERROTADO DEFINITIVAMENTE!      \033[0m\n";
                            cout<<"\n\033[31m======================================================\033[0m\n";
                            historico += "\n   Seu desafio foi o poderoso e misterioso \033[35mBufão\033[0m. A batalha foi ardua, mas infelizmente você foi \033[31mDerrotado\033[0m!.";
                            historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                            cin.ignore(), cin.ignore();
                            desafio = false;
                            fimDeJogo = true;
                            jogoFeito = true;
                            cout << "\033c";
                            break; // retorna menu //
                        }
                    }
                        
                    cout<<"\n\033[31m                         Você foi derrotado...                           ";
                    cout<<"\n                O tempo retrocede e você volta ao seu último checkpoint!\033[0m\n";
                    cin.ignore(), cin.ignore();
                    // restaura atributos
                    vital = vitalCheckpoint, mag = magCheckpoint, forca = forcaCheckpoint, def = defCheckpoint, ouro = ouroCheckpoint, pot = potCheckpoint;
                    bvital = bvitalCheckpoint, bmag = bmagCheckpoint, bforca = bforcaCheckpoint, bdef = bdefCheckpoint;
                    bdef_pro = 0;
                    cenaAtual = 1;
                    cout << "\033c";
                }
                // Condição de "exaustão mágica" (magia zerada) //
                else if ((mag + bmag) <= 0) {
                    if (desafio) {
                        mortes++;
                        if (mortes >= 3) {
                            cout << "\n\033[35m======================================================\033[0m\n";
                            cout << "\n\033[35m       SUA ENERGIA MÁGICA FOI TOTALMENTE ESGOTADA!    \033[0m\n";
                            cout << "\n\033[35m======================================================\033[0m\n";
                            historico += "\n   Durante o confronto com o misterioso \033[35mBufão\033[0m, sua magia se extinguiu por completo, e você foi consumido pelas chamas etéreas e foi \033[31mDerrotado\033[0.";
                            historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
                            cin.ignore(), cin.ignore();
                            desafio = false;
                            fimDeJogo = true;
                            jogoFeito = true;
                            cout << "\033c";
                            break; // retorna menu //
                        }
                    }
                    
                    cout << "\n\033[35m                    Sua energia mágica se esgotou...                      ";
                    cout << "\n           A exaustão o domina, e o tempo retrocede ao último checkpoint.\033[0m\n";
                    cin.ignore(), cin.ignore();
                    // restaura atributos (checkpoint)
                    vital = vitalCheckpoint, mag = magCheckpoint, forca = forcaCheckpoint, def = defCheckpoint, ouro = ouroCheckpoint, pot = potCheckpoint;
                    bvital = bvitalCheckpoint, bmag = bmagCheckpoint, bforca = bforcaCheckpoint, bdef = bdefCheckpoint;
                    bdef_pro = 0;
                    cenaAtual = 1;
                    cout << "\033c";
                }
                                /////////////////////////////////////////////////////////////////
                          
                switch (cenaAtual) {
                    
                // ===== Batalha turno 1 =====
                case 1: {
                
                    cout<<"\n\033[35m  ============================================================================================================  \033[0m\n";
                    cout<<"\n\033[35m                A GRANDE BATALHA CHEGOU - A BUSCA PELO CRISTAL DO MISTERIOSO BUFÃO\033[0m\n"; 
                    cout<<"\n\033[35m  ============================================================================================================  \033[0m\n";
                    
                    // Mostra as vidas restantes em formato de corações
                    vidasRestantes = 3 - mortes;
                    cout<<"\n\033[32m   Vidas :   \033[0m";
                    for (int i = 0; i < vidasRestantes; i++) {
                        cout<< " ❤️ ";
                    }
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                    
                    cout<<"\n\033[35m  ============================================================================================================  \033[0m\n";
                    
                                                    // 1ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                                
                    cout<<"\nA garrafa mágica começa a brilhar com intensidade. O chão desaparece sob seus pés.\n"; 
                    cout<<"Você é sugado por um redemoinho de luz. Ao abrir os olhos, está em um salão escuro coberto de espelhos.\n";
                    cout<<"No centro, um homem de máscara colorida ri e o \033[31mBufão\033[0m, o senhor dos reflexos e do caos.\n";
                    cout<<"\033[34m - Então, você conseguiu me encontrar? Vamos ver se consegue rir quando eu derrotar definitivamente você.\033[0m'\n";
                    cout<<"   1. Confrontar o Bufão com ataque direto.\n"
                        <<"   2. Usar magia defensiva para refletir seus golpes.\n"
                        <<"   3. Invocar o poder do cristal anterior para enfrentar o inimigo."<<endl;
                        
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
                    do {
                        cout<< "\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha;
                        
                        switch (escolha) {
                            case 1:
                                forca -= 10; vital -= 10;
                                cout<<"\n   Resultado 1: Você avança e desfere um golpe certeiro! Mas o reflexo revida e o impacto te derruba.\n";
                                cout<<"   (Força -10, Vitalidade -10)\n";
                                break;
                            case 2:
                                def -= 5; mag -= 5;
                                cout<<"\n   Resultado 2: Você ergue uma barreira de energia! O riso do Bufão ecoa, mas seus ataques voltam contra ele.\n";
                                cout<<"   (Defesa -5, Magia -5)\n";
                                break;
                            case 3:
                                mag -= 10; vital -= 5;
                                cout<<"\n   Resultado 3: A garrafa mágica brilha e o fogo de Ifrit e a pureza da floresta convergem em você!\n";
                                cout<<"   (Magia -10, Vitalidade -5)\n";
                                break;
                            default:
                                cout<<"\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                        }
                    } while (escolha < 1 || escolha > 3);
                                ///////////////////////////////////////////////////////////////// 
                                
                    cin.ignore(), cin.ignore();
                       
                    // __________________________________________________________________________________________________________________________//
                    
                                                    // momento para utilizar uma rolagem de dado //
                    cout << "   O Bufão joga seu dado dourado... ele gira no ar e brilha intensamente!\n";
                    srand(time(NULL)); // semente randômica gerada a partir da hora do sistema
                    for(i=0;i<1;i++){
                        dado=(rand() % 6) + 1; // o % coloca os números gerados entre 0 e o resto da divisão - 1
                        cout<<"\n      E o resultado foi : \033[33m"<<dado<<"       \033[0m\n";  
                    } 
                    
                    switch (dado) {
                        case 1:
                        case 2:
                            vital -= 10;
                            cout<<"\n   O Bufão acerta um golpe traiçoeiro e você sente a força escapar.\n"
                                <<"   (Vitalidade -10)\n";
                            break;
                        case 3:
                        case 4:
                            forca += 5;
                            cout<<"\n   O dado se parte no ar e você aproveita a distração.\n"   
                                <<"   (Força +5)\n";
                            break;
                        default:
                            mag += 10;
                            cout<<"\n   O dado explode em luz! Sua magia absorve o poder.\n"
                                <<"   (Magia +10)\n";
                            break;
                    }
                                
                                    //Atualização de atributos//  
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                    
                    cenaAtual = 2;
                    break;
                } // fim do case 1 do switch cenadas do desafio //
                
                // ===== Batalha turno 2 =====
                case 2: {
                
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore();
                    cout<<"\033[35m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 2ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                                
                    cout<<"\nO Bufão ri enquanto seus reflexos tomam forma. Cada um carrega um pedaço da realidade distorcida.\n"; 
                    cout<<"As risadas ecoam por todos os lados. O chão de vidro treme. Seus reflexos se mexem sozinhos!.\n";
                    cout<<"Você sente que deve agir rápido, antes de perder o controle da própria mente.\n";
                    cout<<"   1. Atacar os reflexos com magia pura.\n"
                        <<"   2. Quebrar o chão e desestabilizar o campo do Bufão.\n"
                        <<"   3. Invocar energia espiritual da garrafa mágica."<<endl;
                        
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
                    do {
                        cout<< "\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha;
                        
                        switch (escolha) {
                            case 1:
                                mag -= 10; forca -= 5;
                                cout<<"\n   Resultado 1: Sua magia explode, destruindo reflexos... mas o Bufão ri, absorvendo parte do poder.\n";
                                cout<<"   (Magia -10, Força -5)\n";
                                break;
                            case 2:
                                vital -= 10; def -= 5;
                                cout<<"\n   Resultado 2: O chão racha e as sombras gritam e o campo etéreo se fragmenta, atingindo vocês dois.\n";
                                cout<<"   (Vitalidade -10, Defesa -5)\n";
                                break;
                            case 3:
                                mag -= 15; vital -= 5;
                                cout<<"\n   Resultado 3: A garrafa mágica brilha e libera fragmentos de espíritos presos.\n";
                                cout<<"   Eles atacam o Bufão, mas drenam parte de sua energia.\n";
                                cout<<"   (Magia -15, Vitalidade -5)\n";
                                break;
                            default:
                                cout<<"\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                        }
                    } while (escolha < 1 || escolha > 3);
                                ///////////////////////////////////////////////////////////////// 
                                
                                    //Atualização de atributos//  
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                        
                    cenaAtual = 3;
                    break;
                } // fim do case 2 do switch cenadas do desafio //
                
                // ===== Batalha turno 3 =====
                case 3: {
                
                    //Para não ir direto para a próxima escolha e perder a leitura do resultado//
                    cout<<"\n\033[34m  Aperte qualquer botão para cotinuar a batalha : \033[0m";
                    cin.ignore(), cin.ignore();
                    cout<<"\033[35m  ____________________________________________________________________________________________________________  \033[0m\n";
                    
                                                    // 3ª Escolha da batalha //
                                /////////////////////////////////////////////////////////////////  
                                
                    cout<<"\n O salão se retorce, o Bufão se desfaz em risos e estilhaços.\n"; 
                    cout<<"Você sente a energia etérea se concentrando no centro da arena.\n";
                    cout<<"O corpo do Bufão parece se dissolver em pura magia e o rosto dele se multiplica, rindo em todas as direções.\n";
                    cout << "\033[34m - Bravo! Bravo! Mas será que consegue rir de si mesmo, mago?\033[0m\n";
                    cout << "A luz da garrafa mágica começa a pulsar, reagindo à distorção.\n";
                    cout << "O ar vibra, o tempo dobra, e você percebe que está diante do momento decisivo.\n";
                    cout << "O que fará?\n";
                    cout<<"   1. Canalizar toda a energia da garrafa para purificar o campo.\n"
                        <<"   2. Absorver a essência do Bufão e dominar seu poder.\n"
                        <<"   3. Golpear com o cajado e selar o riso em silêncio eterno."<<endl;
                        
                    // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
                    // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
                    do {
                        cout<< "\033[33m   Sua escolha será : \033[0m";
                        cin>>escolha;
                        
                        switch (escolha) {
                            case 1:
                                mag -= 10; vital -= 10; def += 10; ouro += 20;
                                cout<<"\n   Resultado 1 : Você ergue a garrafa, liberando uma onda de luz branca que consome os reflexos.\n";
                                cout<<"   O Bufão grita e sua voz se desfaz em cinzas e silêncio.\n";
                                cout<<"   (Magia -10, Vitalidade -10, Defesa +10, Ouro +20)\n";
                                break;
                            case 2:
                                mag += 10; vital -= 15; ouro += 20;
                                cout<<"\n   Resultado 2: Você estende as mãos e absorve a energia distorcida do inimigo.\n";
                                cout<<"   O riso do Bufão ecoa dentro da sua mente... mas agora é sua voz que ri.\n";
                                cout<<"   (Magia +10, Vitalidade -15, Ouro +20)\n";
                                break;
                            case 3:
                                forca += 10; mag -= 5; vital -= 5; ouro += 20;
                                cout<<"\n   Resultado 3: Com o cajado em punho, você desfere um golpe final e o riso é silenciado.\n";
                                cout<<"   O campo etéreo colapsa, e os espelhos se apagam um a um.\n";
                                cout<<"   (Força +10, Magia -5, Vitalidade -5, Ouro +20)\n";
                                break;
                            default:
                                cout<<"\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                        }
                    } while (escolha < 1 || escolha > 3);
                                ///////////////////////////////////////////////////////////////// 
                                
                                    //Atualização de atributos//  
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m"<<endl;
                        
                    if ((vital+bvital) > 0 && (mag + bmag) > 0) {
                        cenaAtual = -1; 
                    } // fim //
                    break;
                } // fim do case 3 do switch cenadas do desafio //
                    default:
                    desafio = false;
                    jogoAtivo = false;
                    break;
                } // fecha switch cenas do desafio //
            } // fim do while do desafio do chefe //
            
            desafio = true, jogoAtivo = true, mortes = 0, cenaAtual = 1;
            
            if (fimDeJogo) {
                break; // encerra o case 1 (volta ao menu)
            }
            
            cout<<"\n\033[33m   //////////////////////////////////////////////////////////////////////\033[0m"<<endl;
            cout<<"\n\033[33m                       !!!LEVEL UP!!!\033[0m"<<endl;
            cout<<"\033[33m               !!!+10 em todos os atributos de combate!!!\033[0m"<<endl;
            cout<<"\033[33m   !!!Ainda é necessário repousar ou curar para ganhar os atributos!!!\033[0m"<<endl;
            cout<<"\n\033[33m   //////////////////////////////////////////////////////////////////////\033[0m"<<endl;
            historico += "\n   A torre de vidro cotninua um segredo. A garrafa mágica entregue pelo mercador desconhecido era uma chave maágica. Você foi engolido por escuridão e enfrentou finalmente nesse mundo o misterioso \033[35mBufão\033[0m. A batalha foi a mais desafiadora e após muita persistência você saiu \033[32mVitorioso\033[0m.";
            cin.ignore(), cin.ignore();
            
            // ............................................................................................................................................................ //
            
                        // Ajustando atributo totais do personagem - !!!LEVEL UP!!!//
            vitalInicial = vitalInicial+10, magInicial = magInicial+10, forcaInicial = forcaInicial+10, defInicial=defInicial+10; // Mago // 
            
            // ............................................................................................................................................................ //
            
                                    // Continuando a jornada //
                                    
            cout << "\033c";
                                    //Atualização de atributos// 
                    cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
                    cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                        <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                        <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;  
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
                                        //18ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n   Você volta ao mundo real longe das trevas que a criatura com roupa de bufão dominava. Você descansa em uma fogueira simples."
                <<"   Após o descanso você se depara com tres caminhos! por onde deseja ir?" <<endl;
            cout<<"      1. Esquerda: \n"
                <<"      2. Direita:\n"
                <<"      3. Meio: "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                
                switch (escolha) {
                    case 1:
                        vital -= 2; ouro -= 3;
                        cout<< "\n   Resultado 1: Você escorregou caiu e perdeu algumas moedas.\n";
                        cout<< "   (Vitalidade -2, Ouro -3)\n";
                        historico += "\n   Quando você voltou do mundo das trevas, apeans descansou em uma fogueira, seguiu para a esquerda e escorregou no caminho perdendo algumas moedas.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 2:
                        ouro = ouro/2; vital = vital*0.1;
                        cout<< "\n   Resultado 2: Você recuperou 10% da sua vitalidade pois encontrou uma maça.\n";
                        cout<< "   (Perdeu metade do ouro, Vitalidade +10%)\n";
                        historico += "\n   Quando você voltou do mundo das trevas, apeans descansou em uma fogueira, seguiu para a direita e comeu uma maça para recuperar as energias.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 3:
                        cout<< "\n   Resultado 3: Você so seguiu o caminho sem nada de diferente.\n";
                        historico += "\n   Quando você voltou do mundo das trevas, apeans descansou em uma fogueira, seguiu em frente sem novos desafios.";
                        cin.ignore(), cin.ignore();
                        break;
                    default:
                        cout << "\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                }
            } while (escolha < 1 || escolha > 3);
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";    
                
                                        //19ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n   Você se deparou com uma casa e nela estava tendo uma festa, voce decide:"<<endl;
            cout<<"      1. Entrar para beber uma com a galera de forma humilde: \n"
                <<"      2. Entrar para beber uma com a galera de forma bruta e agressiva: :\n"
                <<"      3. Passa reto pois voce é careta: "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                
                switch (escolha) {
                    case 1:
                        vital = vital+vitalInicial*0.25, mag = mag+magInicial*0.25, forca = forca+forcaInicial*0.25, def = def+defInicial*0.25;
                        cout<< "\n   Resultado 1: Você ganhou uma recuperação de 25% dos seus atributos.\n";
                        historico += "\n   Ao avistar uma casa festando você entrou e participou ativamente dela recuperando parte das suas energias (+25%).";
                        cin.ignore(), cin.ignore();
                        break;
                    case 2:
                        vital -= 1 , mag -= 1, forca -= 1, def -= 1, ouro = ouro/2;
                        cout<< "\n   Resultado 2: Você perdeu 1 dos seus atributos pois a galera não gostou de voce e te bateu.\n";
                        cout<< "   (Perdeu 1 em cada atributo e metade do seu ouro)\n";
                        historico += "\n   Ao avistar uma casa festando você entrou de forma agressiva e foi hostilizado pelo pessoal que te bateu.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 3:
                        cout<< "\n   Resultado 3: Nada aconteceu, porem voce ouviu de fundo alguem falar olha lá o esquisito!! O -10 de alegria..\n";
                        historico += "\n   Ao avistar uma casa festando você apenas ignorou e seguiu a viagem memso ouvindo ao fundo o pessoal cochichar sobre você.";
                        cin.ignore(), cin.ignore();
                        break;
                    default:
                        cout << "\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                }
            } while (escolha < 1 || escolha > 3);
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";  
                    
                                        //20ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n   Uma donzela em perigo, o que vais fazer? O monstro não vai demorar muito para atacar ela."<<endl;
            cout<<"      1. - Tanto faz! e passa reto : \n"
                <<"      2. Ajuda donzela de forma silenciosa :\n"
                <<"      3. Bate no monstro e foge com ela: "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            // A partir da 13ª escolha mudamos para o modelo de Switch/case para fazer a compilação de escolhas //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha20;
                
                switch (escolha20) {
                    case 1:
                        cout<< "\n   Resultado 1: Nada acontece.\n";
                        historico += "\n   Uma donzela em perigo cruza seu caminho. Você ignora e continua marchando na sua viagem.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 2:
                        forca = forca+forca*0.1, def = def+def*0.1;
                        cout<< "\n   Resultado 2: Ganhou defesa e força nos seus atributos.\n";
                        cout<< "   (Ganhou 10% de defesa e força atual)\n";
                        historico += "\n   Uma donzela em perigo cruza seu caminho. Você ajuda ela silenciosamente para não chamar a atenção do monstro.";
                        cin.ignore(), cin.ignore();
                        break;
                    case 3:
                        vital -= 5, forca -= -5, def -= 5;
                        cout<< "\n   Resultado 3: Você apanha um pouco mas consegue ajudar.\n";
                        cout<< "   (Vitalidade -5, Força -5 e Defesa -5)\n";
                        historico += "\n   Uma donzela em perigo cruza seu caminho. A batalha com o monstro foi dificil e você apanhou um pouco, mas saiu vitorioso.";
                        cin.ignore(), cin.ignore();
                        break;
                    default:
                        cout << "\033[31m   Opção inválida! Digite de 1 a 3.\033[0m\n";
                }
            } while (escolha20 < 1 || escolha20 > 3);
            
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";  
            
                                        //21ª Escolha do jogo//
                    /////////////////////////////////////////////////////////////////
               
            cout<<"\n   Voce esta muito cansado de toda sua jornada e aventuras, voce pode terminar ela de um jeito épico."<<endl;
            cout<<"      1. Segue rumo a casa onde nasceu para ter uma vida em paz. \n"
                <<"      2. Continua sua jornada e enfrenta milhares de oponentes assim provando que é o mais forte :\n"
                <<"      3. Decide enfrentar o seu maior desafio!! CUIDADO: "<<endl;
                
            // Aqui fica toda a opção de escolha e forçando a informação correta para continuar //
            do {
                cout<< "\033[33m      Sua escolha será : \033[0m";
                cin>>escolha;
                if (escolha == 1) {
                    vital = vitalInicial/2, mag = magInicial/2, forca = forcaInicial/2, def = defInicial/2, ouro = 100;
                    cout<<"\n   Resultado 1: Voce chega lá e finalmente descansa, porem esta sozinho. talvez não foi a melhor escolha. "<<endl;
                    historico += "\n   Após incontáveis lutas, você escolheu abandonar o poder e o fardo da magia.";
                    historico += "\n   Regressou à sua terra natal e viveu em paz, lembrando das aventuras e das chamas do Bufão apenas em sonhos.";
                    cin.ignore(), cin.ignore();
                } 
                else if (escolha == 2) {
                    vital = vitalInicial*2, mag = magInicial*2, forca = forcaInicial*2, def = defInicial*2;
                    ouro = ouro/2;
                    cout<<"\n   Resultado 2: Voce se torna um lutador excelente e esta no topo do reino, sendo considerado o melhor soldado do rei, porem está sozinho. talvez não foi a melhor escoha.  : "<<endl;
                    historico += "\n   Dominado pela sede de poder, você seguiu em frente.";
                    historico += "\n   Derrotou guerreiros e reis, ergueu ruínas e monumentos, mas o trono da força revelou-se frio e solitário.";
                    cin.ignore(), cin.ignore();
                   
                }
                else if (escolha == 3) {
                    cout << "\n   Resultado 3: Voce vai contra todos os seus medos e decide ir falar com a donzela que estava em perigo naquele momento. \n";
                        if(escolha20 == 1){
                            cout << "   Voce fala com ela, porem ela lembra de voce passando reto, então, cospe em voce e manda catar coquinho.";
                            cout << "   Que finalzinho ruim ein amigo, moral da história, sempre ajude as pessoas no seu caminho";
                            historico += "\n   Diante da donzela, você encontrou o reflexo de suas próprias escolhas.";
                            historico += "\n   Ignorou o chamado de ajuda e agora colhe o silêncio de quem um dia poderia amá-lo.";
                            cin.ignore(), cin.ignore();
                        }
                        if(escolha20 == 2){
                            cout << "   Ela te acha muito esperto por teres ajudado ela de forma silenciosa e inteligente, voce ganha um belo beijo e volta feliz para casa:";
                            historico += "\n   Ao reencontrar a donzela, você provou que a verdadeira força está na empatia.";
                            historico += "\n   Juntos, partiram para novas aventuras, selando uma amizade eterna.";
                            cin.ignore(), cin.ignore();
                        }
                         if(escolha20 == 3){
                            cout << "   Ela te acha muito forte e bonito, voces se casam e vivem felizes para sempre!! Bater em monstros compensa.";
                            historico += "\n   Você, o bravo mago, encerrou sua jornada com honra.";
                            historico += "\n   Encontrou não apenas a donzela, mas o amor e a redenção. Sua lenda permanecerá viva em cada cristal.";
                            cin.ignore(), cin.ignore();
                        }
                } 
                else {
                    cout<<"\033[31m    Opção inválida! Digite de 1 a 3.\n\n\033[0m";
                }
            } while (escolha < 1 || escolha > 3);
                    /////////////////////////////////////////////////////////////////
                    
            cout << "\033c";
                                    //Atualização de atributos// 
            cout<<"\n\033[32m   Nome do Mago : \033[0m"<<nome<<", o "<<mago<<endl;
            cout<<"\033[32m   Vitalidade : \033[0m"<<vital<<"\033[33m"<<"+"<<bvital<<"\033[0m"<<"\t"<<"\033[32m Magia : \033[0m"<<mag<<"\033[33m"<<"+"<<bmag<<"\033[0"<<"\t"
                <<"\033[32m Força : \033[0m"<<forca<<"\033[33m"<<"+"<<bforca<<"\t"<<"\033[32m Defesa : \033[0m"<<def<<"\033[33m"<<"+"<<bdef<<"\033[0m"<<"\t"
                <<"\033[32m Ouro : \033[0m"<<ouro<<"\t"<<"\033[32m Poções : \033[33m"<<pot<<"\033[0m\n"<<endl;
                
            cout<<"\033[32m  ============================================================================================================  \033[0m\n";
            
            cout<<"\n   Independente das suas escolhas sua jornada chega ao fim. Muitas decisões e batlhas difíceis o provaram no caminho\n";
            cout<<"   Ao final você irá refletir todas as suas ações e viver com as suas consequencias. \n";
            cout<<"   Mas o fim dessa jornada pode ser o começo de outra. Sinta-se \033[32mVITORIOSO\033[0m por chegar até aqui\n";
            cout<<"                                    FIM! ";
            
            cin.ignore();
            
            historico += "\n   Independente das suas escolhas sua jornada chega ao fim. Muitas decisões e batlhas difíceis o provaram no caminho\n";
            historico += "   Ao final você irá refletir todas as suas ações e viver com as suas consequencias. \n";
            historico += "   Mas o fim dessa jornada pode ser o começo de outra. Sinta-se \033[32mVITORIOSO\033[0m por chegar até aqui\n";
            historico += "                                    FIM! ";
            historico += "\n\n\033[32m  ============================================================================================================  \033[0m\n";
            jogoFeito = true;
            
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