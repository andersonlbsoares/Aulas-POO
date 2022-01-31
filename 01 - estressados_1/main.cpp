#include <iostream>
#include <vector>


// FUNÇÕES EXTRA

void imprimir(std::vector<int> vet){
    for (int i : vet) std::cout << i << ' ';
}

void tamanho(std::vector<int> vet){
    std::cout << "Ha " << sizeof vet / sizeof vet[0] <<" pessoas.";
}

//FUNÇÕES DA CATEGORIA BUSCA

void existe(std::vector<int> vet){ //Alguém com o valor X está na fila?
    int tam = vet.size();
    int x = 0;
    std::cout<<"Digite o valor X\n";
    std::cin>>x;
    int situacao = 0;
    for (int i = 0; i < tam; i++){
        if (vet[i]==x) situacao = 1;
    }
    if(situacao == 1) std::cout << "Ha pelo menos uma pessoa com esse valor de stress";        
    if(situacao == 0) std::cout << "Nao ha pessoa com esse valor de stress";        
}

void contar(std::vector<int> vet){ // Quantas vezes o valor X apareceu na fila?
    std::cout<<"Digite o valor X\n";
    int valor = 0;
    int contador = 0;
    int tam = vet.size();
    std::cin >> valor;

    for (int i = 0; i < tam; i++){
        if(vet[i]==valor) contador++;
    }

    std::cout << "Esse valor aparece " << contador << " vez(es).";
}

void procurar_valor(std::vector<int> vet){ //Em que posição da fila aparece X pela primeira vez?
    std::cout<<"Digite o valor X\n";
    int valor = 0;
    int tam = vet.size();
    std::cin >> valor;
    std::vector<int> posicoes{ };

    for (int i = 0; i < tam; i++){
        if(vet[i] == valor) posicoes.push_back(i); 
    }
    
    if(posicoes.size()==1){
        std::cout<<"Valor encontrado na posicao ";
        for (int i : posicoes) std::cout << i << ' ';
    }

    if(posicoes.size()>1){
        std::cout<<"Valor encontrado nas posicoes ";
        
        for (int i : posicoes){
            std::cout << i << ' ';
        }
        
        std::cout<<"\nLogo a primeira posicao e: " << posicoes[0];
    }

    if(posicoes.size()<1){
        std::cout<<"Nenhum valor encontrado";
    }
}

void procurar_valor_apos(std::vector<int> vet){ //Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
    std::cout<<"Informe o valor e a posicao incial, nessa ordem.\n";
    int valor = 0;
    int posicao_inicial = 0;
    std::cin>>valor;
    std::cin>>posicao_inicial;
    int tam = vet.size();
    std::vector<int> posicoes{ };

     for (int i = posicao_inicial; i < tam; i++){
        if(vet[i] == valor) posicoes.push_back(i); 
    }
    
    if(posicoes.size()==1){
        std::cout<<"Valor encontrado na posicao ";
        for (int i : posicoes) std::cout << i << ' ';
    }

    if(posicoes.size()>1){
        std::cout<<"Valor encontrado nas posicoes ";

        for (int i : posicoes){
            std::cout << i << ' ';
        }

        std::cout<<"\nLogo a primeira posicao e: " << posicoes[0];
    }

    if(posicoes.size()<1){
        std::cout<<"Nenhum valor encontrado";
    }
}


//FUNÇÕES DA CATEGORIA MELHOR CASO

void procurar_menor(std::vector<int> vet){// qual o menor valor da lista?
    int tam = vet.size();
    int menor = vet[0];

    for (int i = 0; i < tam; i++){
        if(menor>vet[i])menor = vet[i];
    }

    std::cout<<"O menor valor e "<< menor;    
}

void procurar_maior(std::vector<int> vet){ // qual o maior valor da lista?
    int tam = vet.size();
    int maior = vet[0];

    for (int i = 0; i < tam; i++){
        if(maior<vet[i])maior = vet[i];
    }

    std::cout<<"O maior valor e "<< maior;    
}

void procurar_menor_pos(std::vector<int> vet){ //qual a posição do menor valor da lista?
    std::vector<int> posicoes{ };
    int tam = vet.size();
    int menor = vet[0];

    for (int i = 0; i < tam; i++){
        if(menor>vet[i])menor = vet[i];
    }

    int valor = menor;

    for (int i = 0; i < tam; i++){
        if(vet[i] == valor) posicoes.push_back(i); 
    }
    
    if(posicoes.size()==1){
        std::cout<<"O menor valor foi encontrado na posicao ";
        for (int i : posicoes) std::cout << i << ' ';
    }

    if(posicoes.size()>1){
        std::cout<<"O menor valor foi encontrado nas posicoes ";
        
        for (int i : posicoes){
            std::cout << i << ' ';
        }
        
        std::cout<<"\nLogo a primeira posicao do menor valor e: " << posicoes[0];
    }
}

void procurar_menor_pos_apos(std::vector<int> vet){ //qual a posição do menor valor da lista depois da posição P?
    std::cout<<"A partir de qual posicao devo comecar minha busca?\n";
    int posicao_inicial = 0;
    std::cin>>posicao_inicial;
    std::vector<int> posicoes{ };
    int tam = vet.size();
    int menor = vet[0];

    for (int i = posicao_inicial; i < tam; i++){
        if(menor>vet[i])menor = vet[i];
    }

    int valor = menor;

    for (int i = 0; i < tam; i++){
        if(vet[i] == valor) posicoes.push_back(i); 
    }
    
    if(posicoes.size()==1){
        std::cout<<"O menor valor foi encontrado na posicao ";
        for (int i : posicoes) std::cout << i << ' ';
    }

    if(posicoes.size()>1){
        std::cout<<"O menor valor foi encontrado nas posicoes ";
        
        for (int i : posicoes){
            std::cout << i << ' ';
        }
        
        std::cout<<"\nLogo a primeira posicao do menor valor e: " << posicoes[0];
    }
}

void procurar_melhor_se(std::vector<int> vet){ //qual a posição do HOMEM mais calmo? (menor valor maior que 0)
    int tam = vet.size();
    int menor = 999;

    for (int i = 0; i < tam; i++){
        if(menor>vet[i] && vet[i]>0)menor = vet[i];
    }
    if(menor==999) std::cout<<"Nao ha homens no evento";
    else std::cout<<"O menor valor acima de 0 e "<< menor; 
}

//FUNÇÕES DA CATEGORIA CONTAGEM

void calcular_stress_medio(std::vector<int> vet){ //qual a média de stress da fila? (abs)
    int tam = vet.size();
    int media = 0;

    for (int i = 0; i < tam; i++){
        if(vet[i]<0) vet[i] = vet[i] * -1;
        media = media + vet[i];
    }

    media = media / tam;

    std::cout<<"A media de stress e "<<media;  
}

void mais_homens_ou_mulheres(std::vector<int> vet){ //Na fila existem mais homens ou mulheres?
    int tam = vet.size();
    int mulher = 0;
    int homem = 0;

    for (int i = 0; i < tam; i++){
        if(vet[i]>0)homem++;
        if(vet[i]<0)mulher++;
    }

    if(homem == mulher) std::cout<<"ha a mesma quantidade entre homens e mulheres";
    else if(homem>mulher) std::cout<<"ha mais homens que mulheres";
    else if(homem<mulher) std::cout<<"ha mais mulheres que homens";
}

void qual_metade_eh_mais_estressada(std::vector<int> vet){ //O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
    int tam = vet.size();
    int metade1 = 0;
    int metade2 = 0;
    if(tam%2==0){
        int comeco = tam/2;

        for (int i = comeco; i < tam; i++){
            if(vet[i]<0) vet[i] = vet[i] * -1;
            metade2 = metade2 + vet[i];
        }

        for (int i = 0; i < comeco; i++){
            if(vet[i]<0) vet[i] = vet[i] * -1;
            metade1 = metade1 + vet[i];
        }

    }else{
        std::cout<<"A quantidade de pessoas e impar, entao, o individuo central, sera calculado em ambos os lados\n\n";

        int comeco = tam/2;

        for (int i = comeco; i < tam; i++){
            if(vet[i]<0) vet[i] = vet[i] * -1;
            metade2 = metade2 + vet[i];            
        }

        for (int i = 0; i < comeco+1; i++){
            if(vet[i]<0) vet[i] = vet[i] * -1;
            metade1 = metade1 + vet[i];
        }

    }
    if(metade1 == metade2) std::cout<<"Ambas as partes sao estressadas na mesma proporcao";
    else if(metade1 > metade2) std::cout<<"A primeira metade e mais estressada";
    else if(metade1 < metade2) std::cout<<"A segunda metade e mais estressada";
}

void homens_sao_mais_estressados_que_mulheres(std::vector<int> vet){ //a média do stress dos homens é maior que a das mulheres?
    int tam = vet.size();
    int mulher = 0;
    int homem = 0;

    for (int i = 0; i < tam; i++){
        if(vet[i]>0)homem = homem + vet[i];
        if(vet[i]<0)mulher = mulher + vet[i];
    }

    mulher = mulher * -1;

    if(homem == mulher) std::cout<<"Ambos os lados são estressados na mesma proporcao";
    else if(homem>mulher) std::cout<<"Os homens sao mais estressados";
    else if(homem<mulher) std::cout<<"As mulheres sao mais estressadas";
}

//CENTRAL

int central(){
    std::cout<<"Escolha uma opcao :D\n\n";
    std::cout<<"=====================\n";
    std::cout<<"========BUSCA========\n";
    std::cout<<"=====================\n\n";
    std::cout<<"1 - Alguem com o valor X esta na fila?\n";
    std::cout<<"2 - Quantas vezes o valor X apareceu na fila?\n";
    std::cout<<"3 - Em que posicao da fila aparece X pela primeira vez?\n";
    std::cout<<"4 - Dada a posicao para iniciar a busca, qual a proxima posicao em que aparece X?\n";
    std::cout<<"\n=====================\n";
    std::cout<<"====MELHOR CASO======\n";
    std::cout<<"=====================\n\n";
    std::cout<<"5 - Qual o menor valor da lista?\n";
    std::cout<<"6 - Qual o maior valor da lista?\n";
    std::cout<<"7 - Qual a posicao do menor valor da lista?\n";
    std::cout<<"8 - Qual a posicao do menor valor da lista depois da posicao P?\n";
    std::cout<<"9 - Qual a posicao do HOMEM mais calmo? (menor valor maior que 0)?\n";
    std::cout<<"\n=====================\n";
    std::cout<<"======CONTAGEM=======\n";
    std::cout<<"=====================\n\n";   
    std::cout<<"10 - Qual a media de stress da fila??\n";
    std::cout<<"11 - Na fila existem mais homens ou mulheres?\n";
    std::cout<<"12 - O nivel de stress somado de todas as pessoas da primeira metade e maior que o nivel de stress somado das pessoas da segunda metade da fila?\n";
    std::cout<<"13 - A media do stress dos homens e maior que a das mulheres?\n";
    
    int resposta = 0;
    std::cin>>resposta;
    return resposta;
    
}

int main(){
    
    std::vector<int> vet{ -98, -79, 99, -87};
    int resposta = central();  
    if(resposta==1) existe(vet);
    if(resposta==2) contar(vet);
    if(resposta==3) procurar_valor(vet);
    if(resposta==4) procurar_valor_apos(vet);
    if(resposta==5) procurar_menor(vet);
    if(resposta==6) procurar_maior(vet);
    if(resposta==7) procurar_menor_pos(vet);
    if(resposta==8) procurar_menor_pos_apos(vet);
    if(resposta==9) procurar_melhor_se(vet);
    if(resposta==10) calcular_stress_medio(vet);
    if(resposta==11) mais_homens_ou_mulheres(vet);
    if(resposta==12) qual_metade_eh_mais_estressada(vet);
    if(resposta==13) homens_sao_mais_estressados_que_mulheres(vet);

    return 0;
}