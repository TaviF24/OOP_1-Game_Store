//
// Created by Octavian Farcasi on 11.03.2023.
//
#include <iostream>
class Jocuri{
private:
    bool multiplayer,indicator;
    int *spatiu_ocupat, *pret;
    char *nume, *categorie, *sis_op;
public:
    Jocuri(){
        this->nume=new char[strlen("")+1];
        strcpy(this->nume,"");
        this->categorie=new char[strlen("")+1];
        strcpy(this->categorie,"");
        this->sis_op=new char[strlen("")+1];
        strcpy(this->sis_op,"");
        spatiu_ocupat=new int(-1);
        this->pret=new int(-1);
        multiplayer=false;
        indicator= false;
    }
    Jocuri(char *nume, char *categorie, char *sis_op, const int *spatiu, const int* pret,  bool multiplayer, bool indicator){
        spatiu_ocupat=new int(*spatiu);
        this->pret=new int(*pret);
        this->indicator=indicator;

        size_t lungime;
        if (strcmp(nume, "")!=0){
            lungime= strlen(nume);
            this->nume=new char[lungime+1];
            strcpy(this->nume,nume);}
        else{
            lungime= strlen("Nu exista valoare introdusa");
            this->nume=new char[lungime+1];
            strcpy(this->nume,"Nu exista valoare introdusa");
        }

        if (strcmp(categorie,"")!=0){
            lungime= strlen(categorie);
            this->categorie=new char[lungime+1];
            strcpy(this->categorie,categorie);}
        else{
            lungime= strlen("Nu exista valoare introdusa");
            this->categorie=new char[lungime+1];
            strcpy(this->categorie,"Nu exista valoare introdusa");}

        if (strcmp(sis_op,"")!=0){
            lungime= strlen(sis_op);
            this->sis_op=new char[lungime+1];
            strcpy(this->sis_op,sis_op);}
        else{
            lungime= strlen("Nu exista valoare introdusa");
            this->sis_op=new char[lungime+1];
            strcpy(this->sis_op,"Nu exista valoare introdusa");}

        if (multiplayer!=0)
            this->multiplayer=multiplayer;
    }

    Jocuri(const Jocuri &obiect){
        spatiu_ocupat=new int(*obiect.spatiu_ocupat);
        pret=new int(*obiect.pret);

        size_t lungime= strlen(obiect.nume);
        this->nume=new char[lungime+1];
        strcpy(this->nume,obiect.nume);

        lungime= strlen(obiect.categorie);
        this->categorie=new char[lungime+1];
        strcpy(this->categorie,obiect.categorie);

        lungime= strlen(obiect.sis_op);
        this->sis_op=new char[lungime+1];
        strcpy(this->sis_op,obiect.sis_op);

        this->multiplayer=obiect.multiplayer;
        this->indicator=obiect.indicator;
    }

    ~Jocuri(){
        if(indicator==1){
            delete spatiu_ocupat;
            delete pret;
            delete [] nume;
            delete [] categorie;
            delete [] sis_op;
            std::cout<<"des";
        }
        std::cout<<"tructor\n";

    }

    void setSpatiu(const int *spatiu_nou){
        delete spatiu_ocupat;
        spatiu_ocupat=new int(*spatiu_nou);
    }
    int getSpatiu()const{
        return *spatiu_ocupat;
    }

    void setPret(const int *pret_nou){
        delete pret;
        pret=new int(*pret_nou);
    }
    int getPret()const{
        return *pret;
    }

    void setNume(const char *nume_nou){
        delete [] nume;
        this->nume=new char[strlen(nume_nou)+1];
        strcpy(this->nume,nume_nou);
    }
    char *getNume()const{
        return nume;
    }

    void setCategorie(const char *categorie_nou){
        delete [] categorie;
        this->categorie=new char[strlen(categorie_nou)+1];
        strcpy(this->categorie,categorie_nou);
    }
    char *getCategorie()const{
        return categorie;
    }

    void setSis_Op(const char *sis_op_nou){
        delete [] sis_op;
        this->sis_op=new char[strlen(sis_op_nou)+1];
        strcpy(this->sis_op,sis_op_nou);
    }
    char *getSis_Op()const{
        return sis_op;
    }

    void setMultiplayer(const bool valoare){
        multiplayer=valoare;
    }
    bool getMultiplayer()const{
        return multiplayer;
    }

    void setIndicator(const bool indicator_nou){
        indicator=indicator_nou;
    }

    bool operator==( Jocuri &obiect){
        return strcmp(nume,obiect.nume)==0 && strcmp(categorie,obiect.categorie)==0
               && strcmp(sis_op,obiect.sis_op)==0 && *spatiu_ocupat==*obiect.spatiu_ocupat && *pret==*obiect.pret
               && multiplayer==obiect.multiplayer;
    }
    bool operator!=(const Jocuri &obiect){
        return strcmp(nume,obiect.nume)!=0 || strcmp(categorie,obiect.categorie)!=0
               || strcmp(sis_op,obiect.sis_op)!=0 || *spatiu_ocupat!=*obiect.spatiu_ocupat || *pret!=*obiect.pret
               || multiplayer!=obiect.multiplayer;
    }

    Jocuri operator=(const Jocuri &obiect){
        if(this!=&obiect){
            setNume(obiect.nume);
            setCategorie(obiect.categorie);
            setSis_Op(obiect.sis_op);
            setSpatiu(obiect.spatiu_ocupat);
            setPret(obiect.pret);
            setMultiplayer(obiect.multiplayer);
            setIndicator(obiect.indicator);
        }
        return *this;
    }

    friend std::istream &operator>>(std::istream &ob_in, Jocuri &obiect){
        char sir[100];
        std::cout<<"Nume=";
        ob_in>>sir;
        obiect.setNume(sir);
        std::cout<<"Categorie=";
        ob_in>>sir;
        obiect.setCategorie(sir);
        std::cout<<"Sistem de operare=";
        ob_in>>sir;
        obiect.setSis_Op(sir);

        int nr;
        std::cout<<"Spatiu necesar=";
        ob_in>>nr;
        obiect.setSpatiu(&nr);
        std::cout<<"Pret=";
        ob_in>>nr;
        obiect.setPret(&nr);
        std::cout<<"Multiplayer(1=DA, 0=NU)=";
        ob_in>>nr;
        obiect.setMultiplayer(nr);

        return ob_in;
    }

    friend std::ostream &operator<<(std::ostream &ob_out, Jocuri &obiect) {
        std::cout<<"Nume joc: ";
        if(strcmp(obiect.nume,"")==0)
            std::cout<<"Nu ati introdus numele";
        else
            std::cout<<obiect.nume;
        std::cout<<"\nCategorie: ";

        if(strcmp(obiect.categorie,"")==0)
            std::cout<<"Nu ati introdus categoria";
        else
            std::cout<<obiect.categorie;
        std::cout<<"\nSisteme compatibilie: ";

        if(strcmp(obiect.sis_op,"")==0)
            std::cout<<"Nu ati introdus sistemele compatibile";
        else
            std::cout<<obiect.sis_op;
        std::cout<<"\nSpatiu necesar: ";

        if(*obiect.spatiu_ocupat==-1)
            std::cout<<"Nu ati introdus spatiul";
        else
            std::cout<<*obiect.spatiu_ocupat<<"GB";
        std::cout<<"\nPret: ";

        if(*obiect.pret==-1)
            std::cout<<"Nu ati introdus pretul";
        else
            std::cout<<*obiect.pret<<"€";

        std::cout<<"\nMultiplayer: ";
        if (obiect.multiplayer==1)
            ob_out<<"Da\n";
        else
            ob_out<<"Nu\n";
        return ob_out;
    }


    void afis()const{
        std::cout<<nume<<" "<<categorie<<" "<<sis_op<<" "<<*spatiu_ocupat<<" "<<*pret<<" "<<multiplayer<<"\n";
    }


};

void start(){
    std::cout<<"\n\n\n      MENIU"<<"\n";
    std::cout<<"\nSTART: APASATI 1\n";
    std::cout<<"EXIT: APASATI 2\n"<<"\n";

    bool multiplayer;
    int spatiu_ocupat, pret, x, dimensiune=0;
    char nume[50], categorie[50], sis_op[50];


    std::cin>>x;
    if(x==1){
        //Jocuri *v_cel_mai=new Jocuri[dimensiune];
        Jocuri *v_bun=new Jocuri[dimensiune];
        v_bun[0]=Jocuri();
        while(x!=2){
            std::cout<<"Doriti sa adaugati un nou element?\nDA: Apasati 1\nNU: Apasati 2\n";
            std::cin>>x;
            if(x==1){
                if(dimensiune!=0) {
                    Jocuri *v_copie = new Jocuri[dimensiune];
                    for (int i = 0; i < dimensiune; i++)
                        v_copie[i] = v_bun[i];
                    for (int i = 0; i < dimensiune; i++)
                    {
                        v_bun[i].setIndicator(true);
                        v_bun[i].~Jocuri();
                    }
                    //delete [] v_bun;
                    v_bun=new Jocuri[dimensiune+1];
                    for (int i = 0; i < dimensiune; i++)
                        v_bun[i] = v_copie[i];
                    for (int i = 0; i < dimensiune; i++)
                    {
                        v_copie[i].setIndicator(true);
                        v_copie[i].~Jocuri();
                    }
                    //delete [] v_copie;
                }
//                else{
//                    v_bun[0]=Jocuri();
//                }
                v_bun[dimensiune]=Jocuri();

                std::cout<<"Nume= tastati 3\n";
                std::cout<<"Categorie= tastati 4\n";
                std::cout<<"Sistem de operare= tastati 5\n";
                std::cout<<"Spatiu_ocupat= tastati 6\n";
                std::cout<<"Pret= tastati 7\n";
                std::cout<<"Multiplayer= tastati 8\n";
                std::cout<<"Terminati= tastati 9\n";

                int indice;
                std::cin>>indice;
                while(indice!=9){
                    if(indice==3) {
                        std::cout<<"Nume= "; std::cin >> nume;
                        v_bun[dimensiune].setNume(nume);
                    }
                    if(indice==4){
                        std::cout<<"Categorie= ";std::cin>>categorie;
                        v_bun[dimensiune].setCategorie(categorie);
                    }
                    if(indice==5){
                        std::cout<<"Sistem de operare= ";std::cin >> sis_op;
                        v_bun[dimensiune].setSis_Op(sis_op);

                    }
                    if(indice==6) {
                        std::cout<<"Spatiu_ocupat= ";std::cin>>spatiu_ocupat;
                        v_bun[dimensiune].setSpatiu(&spatiu_ocupat);
                    }
                    if(indice==7) {
                        std::cout<<"Pret in euro= ";std::cin >> pret;
                        v_bun[dimensiune].setPret(&pret);
                    }
                    if(indice==8){
                        std::cout<<"Multiplayer=";std::cin>>multiplayer;
                        v_bun[dimensiune].setMultiplayer(multiplayer);
                    }
                    std::cin>>indice;
                }
                int ok=0;
                for(int i=0;i<dimensiune;i++){
                    if(v_bun[i]==v_bun[dimensiune]){
                        ok=1;
                        break;
                    }
                }
                if(ok==1){
                    std::cout<<"\nAti mai adaugat deja acest joc\n\n";
                    v_bun[dimensiune].setIndicator(true);
                    v_bun[dimensiune].~Jocuri();
                }else
                    dimensiune++;
            }
        }
        if(dimensiune!=0){
            std::cout<<"\nDoriti sa modicati vreun joc?\nDA: Apasati 1\nNU: Apasati 2\n";
            std::cin>>x;
            while(x!=2){
                int i,indice=1;
                std::cout<<"Alegeti jocul:\n";
                for(i=0;i<dimensiune;i++){
                    std::cout<<"Jocul "<<i+1<<" "<<v_bun[i].getNume()<<"\n";
                }
                std::cin>>i;i--;
                std::cout<<"Nume= tastati 3\n";
                std::cout<<"Categorie= tastati 4\n";
                std::cout<<"Sistem de operare= tastati 5\n";
                std::cout<<"Spatiu_ocupat= tastati 6\n";
                std::cout<<"Pret= tastati 7\n";
                std::cout<<"Multiplayer= tastati 8\n";
                std::cout<<"Daca doriti sa va opriti, apasati 9\n";
                std::cin>>indice;
                while(indice!=9){
                    if(indice==3) {
                        std::cout<<"Nume= "; std::cin >> nume;
                        v_bun[i].setNume(nume);
                    }
                    if(indice==4){
                        std::cout<<"Categorie= ";std::cin>>categorie;
                        v_bun[i].setCategorie(categorie);
                    }
                    if(indice==5){
                        std::cout<<"Sistem de operare= ";std::cin >> sis_op;
                        v_bun[i].setSis_Op(sis_op);

                    }
                    if(indice==6) {
                        std::cout<<"Spatiu_ocupat= ";std::cin>>spatiu_ocupat;
                        v_bun[i].setSpatiu(&spatiu_ocupat);
                    }
                    if(indice==7) {
                        std::cout<<"Pret in euro= ";std::cin >> pret;
                        v_bun[i].setPret(&pret);
                    }
                    if(indice==8){
                        std::cout<<"Multiplayer=";std::cin>>multiplayer;
                        v_bun[i].setMultiplayer(multiplayer);
                    }
                    std::cin>>indice;
                }

                std::cout<<"Daca nu mai modificati vreun joc, apasati 2, altfel apasati 3\n";
                std::cin>>x;
            }
        }

        for(int i=0;i<dimensiune;i++){
            std::cout<<"Jocul "<<i+1<<"\n"<<v_bun[i]<<"\n";
            v_bun[i].setIndicator(true);
            v_bun[i].~Jocuri();
        }

    }

    std::cout<<"SFARSIT";

}



int main() {

    start();

    return 0;
}
// nume, categorie, spatiu ocupat, pret, sistem de operare compatibil, multiplayer/singleplayer


