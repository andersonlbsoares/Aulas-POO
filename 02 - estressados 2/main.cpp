#include <iostream>
#include <vector>

void imprimir(std::vector<int> vet){
    for (int i : vet) std::cout << i << ' ';
}

std::vector<int> clonar(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    return vetornovo;
}

std::vector<int> pegar_homens(const std::vector<int>& vet){
    std::vector<int> vetornovo{};
    for (int i : vet) if(i>0) vetornovo.push_back(i);
    return vetornovo;
}

std::vector<int> pegar_calmos(const std::vector<int>& vet){
    std::vector<int> vetornovo{};
    for (int i : vet) if(i>0 && i<11) vetornovo.push_back(i);
    return vetornovo;
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& vet){
    std::vector<int> vetornovo{};
    for (int i : vet) if(i>-10 && i<0) vetornovo.push_back(i);
    return vetornovo;
}

std::vector<int> inverter_com_copia(const std::vector<int>& vet){
    std::vector<int> vetornovo{};
    for (int i = vet.size()-1; i >= 0 ; i--) vetornovo.push_back(vet[i]);
    return vetornovo;
}

std::vector<int> reverter_inplace(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    int aux;
    int valorfinal = 0;
    int tamanho = vetornovo.size();
    for (int j = tamanho; j >= 0 ; j--){
        for (int i = tamanho; i >= 0 ; i--){
            if (i == tamanho) valorfinal = vetornovo[i]; 
            aux = vetornovo[i-1];
            vetornovo[i-1] = vetornovo[i];
            vetornovo[i] = aux;
            if (i == 0) vetornovo[0] = valorfinal; 
        } 
    } 
    return vetornovo;
}

int sortear(const std::vector<int>& vet){
    int valoraletario = rand()%(vet.size()+1);
    return vet[valoraletario];
}

std::vector<int> embaralhar(const std::vector<int>& vet){
    std::vector<int> vetornovo = vet;
    for (int i = 0; i < vetornovo.size(); i++){
		int r = rand() % vetornovo.size();
		int temp = vetornovo[i];
		vetornovo[i] = vetornovo[r];
		vetornovo[r] = temp;
	}
    return vetornovo;
}

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

std::vector<int> exclusivos(const std::vector<int>& vet){
    std::vector<int> vetornovo = ordenar(vet);
    std::vector<int> vetornovofinal;
    for (int i = 0; i < vetornovo.size(); i++){
        if (vetornovo[i+1]==vetornovo[i]){ 
        }else{
            vetornovofinal.push_back(vetornovo[i]);
        }
    }
return vetornovofinal;
}

std::vector<int> diferentes(const std::vector<int>& vet){
        std::vector<int> vetornovo = ordenar(vet);
    std::vector<int> vetornovofinal;
    for (int i = 0; i < vetornovo.size(); i++){
        if (vetornovo[i+1]==vetornovo[i]){ 
        }else if(vetornovo[i]<0){
        }else{
            vetornovofinal.push_back(vetornovo[i]);
        }
    }
return vetornovofinal;
}

std::vector<int> abandonados(const std::vector<int>& vet){
    std::vector<int> vetornovo = ordenar(vet);
    std::vector<int> vetornovofinal;
    for (int i = 0; i < vetornovo.size(); i++){
        if (vetornovo[i+1]==vetornovo[i]){ 
            vetornovo[i] = 0;
        }
    }
    for (int i = 0; i < vetornovo.size(); i++){
        if (!(vetornovo[i]==0)){
            vetornovofinal.push_back(vetornovo[i]);
        }
    }
return vetornovofinal;
}


int central(){
    std::cout<<"Escolha uma opcao :D\n\n";
    std::cout<<"=====================\n";
    std::cout<<"========FILTER=======\n";
    std::cout<<"=====================\n\n";
    std::cout<<"1 - retorna um novo vetor copiando os valores do vetor de entrada\n";
    std::cout<<"2 - retorne uma lista com os homens\n";
    std::cout<<"3 - retorne uma lista com as pessoas com stress menor que 10 (positivos menor que 10)\n";
    std::cout<<"4 - retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)\n";
    std::cout<<"\n=====================\n";
    std::cout<<"========Acesso=========\n";
    std::cout<<"=====================\n\n";
    std::cout<<"5 - retorna um novo vetor com os dados invertidos\n";
    std::cout<<"6 - inverte os valores do vetor de entrada sem uso de vetor auxiliar\n";
    std::cout<<"7 - retorna aleatoriamente um elemento do vetor\n";
    std::cout<<"8 - embaralha o vetor original\n";
    std::cout<<"9 - ordena o vetor original\n";
    std::cout<<"\n=====================\n";
    std::cout<<"======Conjuntos=======\n";
    std::cout<<"=====================\n\n";   
    std::cout<<"10 - O fiscal permitiu a entrada de um único representante de cada valor, ou seja, uma lista dos valores que aparecem na fila sem repetição. Que conjunto foi formado?\n";
    std::cout<<"11 - Qual a lista dos diferentes níveis de stress que aparecem?\n";
    std::cout<<"12 - quais pessoas ficaram na fila após remover um exemplar de cada valor?\n";
    
    int resposta = 0;
    std::cin>>resposta;
    return resposta;
    
}

int main(){
    
    std::vector<int> vet{14, 54, 85, 3, 4, 3, -1, -2, -2, -15};
    int resposta = central();  
    if(resposta==1) {
        std::vector<int> vetornovo = clonar(vet);
        imprimir(vetornovo);
    }
    else if(resposta==2) {
        std::vector<int> vetornovo = pegar_homens(vet);
        imprimir(vetornovo);
    }
    else if(resposta==3) {
        std::vector<int> vetornovo = pegar_calmos(vet);
        imprimir(vetornovo);
    }
    else if(resposta==4){
        std::vector<int> vetornovo = pegar_mulheres_calmas(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==5){
        std::vector<int> vetornovo = inverter_com_copia(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==6){
        std::vector<int> vetornovo = reverter_inplace(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==7){
        std::cout<< sortear(vet);
    } 
    else if(resposta==8){
        std::vector<int> vetornovo = embaralhar(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==9){
        std::vector<int> vetornovo = ordenar(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==10){
        std::vector<int> vetornovo = exclusivos(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==11){
        std::vector<int> vetornovo = diferentes(vet);
        imprimir(vetornovo);
    } 
    else if(resposta==12){
        std::vector<int> vetornovo = abandonados(vet);
        imprimir(vetornovo);
    } 

    return 0;
}