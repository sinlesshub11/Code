#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool is_prime(int num) {
    if(num<=1)return false;
    for(int i=2;i*i<=num;i++){
        if(num % i ==0)return false;
    }
    return true;
}
void generate_primes(int start,int end,int*primes,int*count){
    for(int i =start;i<= end ;i++){
        if(is_prime(i)){
            primes[*count]=i;
            (*count)++;
        }
    }
}
void find_equidistant_primes(int*primes,int count){
    int triplets[1000][4];
    int triplet_count = 0;
    for (int i=0;i<count;i++){
        int prime = primes[i];
        
        for(int j=0;j<count;j++){
            if(i!=j){
                int p1=primes[j];
                int distance = abs(prime -p1);
                
                for(int k = 0;k< count;k++){
                    if(k!=i && k!=j){
                        int p2 = primes[k];
                        if(abs(prime -p2)==distance){
                            if(p1<prime && p2>prime){
                                triplets[triplet_count][0]=p1;
                                triplets[triplet_count][1]=prime;
                                triplets[triplet_count][2]=p2;
                                triplets[triplet_count][3]=distance;
                                triplet_count++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i< triplet_count-1;i++){
        for(int j=i+1; j<triplet_count;j++){
            if(triplets[i][0]>triplets[j][0]){
            int temp[4];
            for(int k=0;k<4;k++){
                temp[k]= triplets[i][k];
                triplets[i][k] = triplets[j][k];
                triplets[j][k] = temp[k];
                }
            }
            else if(triplets[i][0]==triplets[j][0] && triplets[i][1]>triplets[j][1]){
                 int temp[4];
            for(int k=0;k<4;k++){
                temp[k]= triplets[i][k];
                triplets[i][k] = triplets[j][k];
                triplets[j][k] = temp[k];
                
            }
            }
            }
        }
        int last_prime = -1;
        for(int i=0;i<triplet_count;i++){
            int p1 = triplets[i][0];
            int prime = triplets[i][1];
            int p2 = triplets[i][2];
            int distance = triplets[i][3];
            if(prime != last_prime){
                if(last_prime != -1){
                }
                last_prime =prime;
            }
            printf("%d %d %d %d\n",p1,prime,p2,distance);
        }
            
        }
        int main(){
            int start,end;
            int primes[1000],count = 0;
            scanf("%d %d",&start,&end);
             generate_primes(start, end,primes,&count);
             find_equidistant_primes(primes,count);
             return 0;
            
        }
