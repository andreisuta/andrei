#include <iostream>
using namespace std;
class Multime{
private:
    int cardinal;
    int elemente[100];
public:
    Multime(){
        cin>>cardinal;
        for(int i=0;i<cardinal;i++)
            cin>>elemente[i];
    }
    Multime(int x){
        this->cardinal=x;

    }
    int getCardinal(){
        return this->cardinal;
    }
    int getElemente(int x){
        return elemente[x];
    }

    void setCardinal(int x){
        cardinal=x;
    }
    void setElemente(int x, int y){
        elemente[x]=y;
    }

    Multime(const Multime &x2) {
        cardinal = x2.cardinal;
        elemente[cardinal] = x2.elemente[cardinal];
     }



    void MultimeMaking(){
        int i, aux;
        for(i=0;i<cardinal-1;i++){
            for(int j=i+1;j<cardinal;j++){
                if(elemente[i]>elemente[j]){
                    aux=elemente[i];
                    elemente[i]=elemente[j];
                    elemente[j]=aux;
                  
                }
            }
            
        }
        for(int i=0; i<cardinal-1; i++){
            if(elemente[i]==elemente[i+1]){
                for(int j=i+1; j<cardinal-1; j++)
                    elemente[j]=elemente[j+1];
                cardinal--;
                i--;


            }

            }

        }
    Multime operator+(const Multime& other){
        Multime Reuniune(0);
        Reuniune.cardinal=cardinal + other.cardinal;
        for(int i=0; i<cardinal; i++){
            Reuniune.elemente[i]=elemente[i];
        }
        for(int i=0; i<=other.cardinal; i++){
            Reuniune.elemente[cardinal+i]=other.elemente[i];
        }

        return Reuniune;
    }
    Multime operator*(const Multime& other){
        int k=0;
        Multime Intersectie(0);
        for(int i=0;i<cardinal;i++){
            for(int j=0;j<other.cardinal;j++){
                if(elemente[i]==other.elemente[i]){
                    Intersectie.elemente[k]=elemente[i];
                    k++;
                }
            }
        }
        Intersectie.cardinal=k;
        return Intersectie;
    }
    Multime operator-(const Multime& other){
        Multime Diferenta(0);
        int k=0;
        int count=0;
        int j;
        Diferenta.cardinal=cardinal + other.cardinal;
        for(int i=0; i<cardinal; i++){
            count=0;
            for(j=0; j<other.cardinal; j++){
                if(elemente[i]==other.elemente[j])
                    count++;
            }
            if(count==0 && j==other.cardinal) {
                Diferenta.elemente[k] = elemente[i];
                k++;
            }

            }
        Diferenta.cardinal=k;
        return Diferenta;
        }
        ~Multime(){
        cardinal=0;
    }

    };





int main(){
    int x, y;
    Multime R;

    Multime X;

    X.MultimeMaking();
    R.MultimeMaking();
    Multime Intersectie(0);
    Intersectie=R * X;
    Intersectie.MultimeMaking();
    for(int i=0; i<Intersectie.getCardinal(); i++){
        cout<<Intersectie.getElemente(i)<< " ";
    }
    cout<<endl;
    Multime Reuniune(0);
    Reuniune=R + X;
    Reuniune.MultimeMaking();
    for(int i=0; i<Reuniune.getCardinal(); i++)
        cout<<Reuniune.getElemente(i)<<" ";
    cout<<endl;
    Multime Diferenta(0);
    Diferenta=R - X;
    Diferenta.MultimeMaking();
    for(int i=0; i<Diferenta.getCardinal(); i++)
        cout<<Diferenta.getElemente(i)<<" ";
    return 0;
}
