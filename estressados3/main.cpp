#include <iostream>
#include <vector>

std::vector<int> ordenar(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int aux;
    int troca = 1;
    while (troca == 1){
        troca = 0;        
        for (int i = 0; i < vetornovo.size(); i++){
            if (vetornovo[i] > vetornovo[i + 1]){
                troca = 1;
                aux = vetornovo[i];
                vetornovo[i] = vetornovo[i + 1];
                vetornovo[i + 1] = aux;
            }
        }
    }
    return vetornovo;
}

void imprimir(std::vector<int> vet){
    for (int i : vet) std::cout << i << ' ';
}

std::vector<int> sozinhos(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    
    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]<0)vetornovo[i]=vetornovo[i]*-1;
    }
    std::vector<int> vetoraux = vetornovo;

    for (int i = 0; i < vetornovo.size(); i++){
        vetoraux[i]=0;
        for (int j = 0; j < vetoraux.size(); j++){
            if(vetornovo[i]==vetornovo[j]){
                vetoraux[i]++;
            }
        }
    }
    std::vector<int> vetorfinal;
    
    for (int i = 0; i < vetoraux.size(); i++){
            if(vetoraux[i]==1) vetorfinal.push_back(vetornovo[i]);
    }

return vetorfinal;   
}

void mais_ocorrencias(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    
    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]<0)vetornovo[i]=vetornovo[i]*-1;
    }
    std::vector<int> vetoraux = vetornovo;

    for (int i = 0; i < vetornovo.size(); i++){
        vetoraux[i]=0;
        for (int j = 0; j < vetoraux.size(); j++){
            if(vetornovo[i]==vetornovo[j]){
                vetoraux[i]++;
            }
        }
    }
    std::vector<int> vetorfinal;
    int maior = 0;
    int maiorposicao = 0;
    for (int i = 0; i < vetoraux.size(); i++){
        if(maior<vetoraux[i]){
            maior=vetoraux[i];
            maiorposicao = i;
        } 
    }
    
    std::cout<<vetornovo[maiorposicao];

    
}

std::vector<int> mais_recorrentes(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    
    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]<0)vetornovo[i]=vetornovo[i]*-1;
    }
    std::vector<int> vetoraux = ordenar(vetornovo);
    std::vector<int> vetornovoo = ordenar(vetornovo);

    for (int i = 0; i < vetornovoo.size(); i++){
        vetoraux[i]=0;
        for (int j = 0; j < vetoraux.size(); j++){
            if(vetornovoo[i]==vetornovoo[j]){
                vetoraux[i]++;
            }
        }
    }
    std::vector<int> vetorfinal;
    
    for (int i = 0; i < vetoraux.size(); i++){
            if(vetoraux[i]>1 && vetornovoo[i] != vetornovoo[i+1]) vetorfinal.push_back(vetornovoo[i]);
    }

return vetorfinal; 
}

void briga(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int total=0;
    for (int i = 1; i < vetornovo.size(); i++){
        if(vetornovo[i]>49&&vetornovo[i-1]>29&&vetornovo[i+1]>29) total++;
    }
    std::cout<<"Essa situação ocorreu "<<total<<" vezes";    

}

std::vector<int> apaziguado(const std::vector<int>& vet){
    std::vector<int> thisvet= vet;
    std::vector<int> vetornovo{};

    for (int i = 0; i < thisvet.size(); i++){
        if(thisvet[i]<0) thisvet[i] =thisvet[i] * -1;
    }
    
    for (int i =0; i < thisvet.size(); i++){
        if( thisvet[i]>80 &&(thisvet[i-1]<10 || thisvet[i+1]<10))vetornovo.push_back(i);
    }
    return vetornovo;
}

void quantos_times(const std::vector<int>& vet){
    std::vector<int> thisvet= vet;
    int qntd=0;
    for (int i = 0; i < thisvet.size(); i++)if((thisvet[i]<0 && thisvet[i+1]>0) || (thisvet[i]>0 && thisvet[i+1]<0))qntd++;
    std::cout<<qntd;

}

void maiortime(const std::vector<int>& vet){
    std::vector<int> thisvet= vet;
    int qntd=0;
    int contador = 0;
    int contadormaior = 0;
    int posicao = 0;
    int posicaofinal = 0;
    for (int i = 0; i < thisvet.size(); i++){
        if((thisvet[i]<0 && thisvet[i+1]>0) || (thisvet[i]>0 && thisvet[i+1]<0)){
            qntd++;
            contador = 0;
        }else{
            contador++;
            posicao = i;
        }

        if(contadormaior<contador){
            contadormaior = contador;
            posicaofinal = posicao;
        }

    }
        posicaofinal++;
        contadormaior++;
        int posfim = posicaofinal - contadormaior+1;
    for (int i = posicaofinal; i >=posfim; i--){
        std::cout<<thisvet[i]<<" ";
    }
    

}

void sozinhostime(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int cont=0;
    for (int i = 1; i < vetornovo.size(); i++){
        if((vetornovo[i]>0 && vetornovo[i-1]<0 && vetornovo[i+1]<0) || (vetornovo[i]<0 && vetornovo[i-1]>0 && vetornovo[i+1]>0) )cont++;
	}
    std::cout<<"Há "<<cont<<" pessoas sozinhas.";
}

std::vector<int> casais(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    std::vector<int> casais;
    int aux = 0;
    for (int i = 0; i < vetornovo.size(); i++){
        aux = vetornovo[i] *-1;
        for (int j = 0; j < vetornovo.size(); j++){
            if(vetornovo[j] == aux) casais.push_back(vetornovo[i]);
        }
    }
    
    return casais;
}

std::vector<int> trios(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    std::vector<int> trios;

    for (int i = 0; i <vetornovo.size(); i++){
        if(vetornovo[i]<0) vetornovo[i] = vetornovo[i] * -1; 
    }

    int aux=0;
    for (int i = 0; i < vetornovo.size(); i++){
        aux = vetornovo[i];
        int qntd = 0;
        for (int j = 0; j < vetornovo.size(); j++){
            if(vetornovo[j] == aux) qntd++; 
        }
        if(qntd>=3) trios.push_back(vetornovo[i]);
    }
    
    return trios;
}

std::vector<int> remove(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int aremover=0;
    std::cin >> aremover;

    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]==aremover) vetornovo.erase(vetornovo.begin()+i);
    }
 return vetornovo;       
}

std::vector<int> remove2(const std::vector<int>& vet, int aremover){
    std::vector<int> vetornovo = vet;
    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]==aremover) vetornovo.erase(vetornovo.begin()+i);
    }
 return vetornovo;       
}

std::vector<int> insert(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int valor=0;
    int posicao=0;
    std::cout<<"Insira valor e posição";
    std::cin >> valor;
    std::cin >> posicao;

  std::vector<int>::iterator it;

  it = vetornovo.begin()+posicao;
  it = vetornovo.insert (it, valor);

return vetornovo;
}

std::vector<int> dance(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int bol = 1;
    for (int i = 0; i < vetornovo.size(); i++){
        if(vetornovo[i]<0)vetornovo[i] = vetornovo[i]* -1;    
    }
    while(bol == 1){
        bol = 0;
        for (int i = 0; i < vetornovo.size(); i++){
            if(vetornovo[i] ==vetornovo[i+1]){
                vetornovo = remove2(vetornovo,vetornovo[i]);
                vetornovo = remove2(vetornovo,vetornovo[i+1]);
                bol = 1;
            }
        }
    }
    return vetornovo;
}

int central(){
    std::cout<<"Escolha uma opcao :D\n\n";
    std::cout<<"=====================\n";
    std::cout<<"==========MAP========\n";
    std::cout<<"=====================\n\n";
    std::cout<<"1 - Quais PESSOAS eram as únicas representantes do seu nível de stress na fila?\n";
    std::cout<<"2 - Qual a maior quantidade de ocorrências do mesmo nível de stress.\n";
    std::cout<<"3 - Quais os níveis de stress mais recorrentes\n";
    std::cout<<"\n=====================\n";
    std::cout<<"========proximidade====\n";
    std::cout<<"=====================\n\n";
    std::cout<<"4 - Quando alguém super estressado(>50) está ao lado de duas pessoas muito estressadas(>30) pode dar briga. Quantas vezes essa situação acontece?\n";
    std::cout<<"5 - Se alguém hiper estressado(>80) estiver ao lado de pelo menos uma pessoa bem tranquila (<10) ela vai ser apaziguada. Em que posições estão esses que serão apaziguados?\n";
    std::cout<<"\n=====================\n";
    std::cout<<"======Sequências=======\n";
    std::cout<<"=====================\n\n";   
    std::cout<<"6 - Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?\n";
    std::cout<<"7 - Qual o maior time que apareceu na fila?\n";
    std::cout<<"8 - Quantas pessoas não estavam em um time?\n";
    std::cout<<"\n=====================\n";
    std::cout<<"========Grupos=========\n";
    std::cout<<"=====================\n\n";
    std::cout<<"9 - Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados?\n";
    std::cout<<"10 - Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?\n"; 
    std::cout<<"\n=====================\n";
    std::cout<<"======Alteração=======\n";
    std::cout<<"=====================\n\n"; 
    std::cout<<"11 - Dado a pessoa X, como fica a fila após remover X?\n";
    std::cout<<"12 - Como fica a fila se eu inserir a pessoa X na posição Y.\n";
    std::cout<<"13 - O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes se formavam novos pares que também saíam. Quem ficou na fila?\n";
    int resposta = 0;
    std::cin>>resposta;
    return resposta;
    
}

int main(){
    
    std::vector<int> vet{31, 85, 2, 2, 3, 4, -1, -2,-3,-91, -15};
    int resposta = central();  
    if(resposta==1) {
        std::vector<int> vetornovo = sozinhos(vet);
        imprimir(vetornovo);
    }
    else if(resposta==2) {
        mais_ocorrencias(vet);
    }
    else if(resposta==3) {
        std::vector<int> vetornovo = mais_recorrentes(vet);
        imprimir(vetornovo);
    }
    else if(resposta==4){
        briga(vet);
    } 
    else if(resposta==5){
        std::vector<int> vetornovo = apaziguado(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==6){
        quantos_times(vet);
    } 
    else if(resposta==7){
        maiortime(vet);
    } 
    else if(resposta==8){
        sozinhostime(vet);
    } 
    else if(resposta==9){
        std::vector<int> vetornovo = casais(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==10){
        std::vector<int> vetornovo = trios(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==11){
        std::vector<int> vetornovo = remove(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==12){
        std::vector<int> vetornovo = insert(vet);
        imprimir(vetornovo);
    }
    else if(resposta==13){
        std::vector<int> vetornovo = dance(vet);
        imprimir(vetornovo);
    }  

    return 0;
}
