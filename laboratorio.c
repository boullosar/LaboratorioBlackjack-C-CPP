#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main(){
    int n1=0, n2=0, mj1=0, mj2=0, apuesta1=0, apuesta2=0, sumaC1=0, sumaC2=0, sumaCr, num, otracarta, aumento1=0, aumento2=0, cantap1=0, cantap2=0;
    //n1 = posicion de la letra en el nombre del jugador 1
    //n2 = posicion de la letra en el nombre del jugador 2
    //mj1 = monto total del jugador 1
    //mj2 = monto total del jugador 2
    //apuesta1 = total apuesta del jugador 1
    //apuesta2 = total apuesta del jugador 2
    //sumaC1 = suma del valor de las cartas del jugador 1
    //sumaC2 = suma del valor de las cartas del jugador 2
    //sumaCr = suma de las cartas del crupier
    //num = valor de la carta generado aleatoriamente
    //otracarta = numero al azar (0 o 1) con el que el croupier elige o no sacar otra carta
    //aumento1 = aumento de la apuesta jugador 1
    //aumento2 = aumento de la apuesta jugador 2
    //cantap1 = cantidad de apuestas >0 del jugador 1
    //cantap2 = cantidad de apuestas >0 del jugador 2

    char letra, nj1[20], nj2[20], opciones='J', aceptacion;
    //letra = letra ingresada para el nombre
    //nj1 = nombre del jugador 1
    //nj2 = nombre del jugador 2
    //opciones = opciones del mensaje de menu (J, V, S)
    //acpetacion = opciones del mensaje de aceptacion (J, T)

    bool j1termina=false, j2termina=false, j1perdio=false, j2perdio=false;
    //j1termina se pone en true cuando el jugador 1 suma >=21 o decide Terminar
    //j2termina se pone en true cuando el jugador 2 suma >=21 o decide Terminar
    //j1perdio se pone en true cuando el jugador 1 suma >21
    //j2perdio se pone en true cuando el jugador 2 suma >21

    srand(time(NULL));//numeros aleatorios

    printf("Bienvenidos/as, por  favor ingresen sus datos: \n");
    
    //pedir nombre j1
    printf("[Jugador 1]\n");
    printf("Nombre: ");
    scanf(" %c", &letra);
    while(letra!='\n'){
        nj1[n1]=letra;
        n1++;
        scanf("%c", &letra);
    }
    printf("Monto inicial: ");
    scanf("%d", &mj1);
    while(mj1>1000 || mj1<50){
        printf("Error, revise que todo este en orden\n");
        printf("Monto inicial: ");
        scanf("%d", &mj1);
    }
    printf("\n");

    //pedir nombre j2
    printf("[Jugador 2]\n");
    printf("Nombre: ");
    scanf(" %c", &letra);
    while(letra!='\n'){
        nj2[n2]=letra;
        n2++;
        scanf("%c", &letra);
    }
    printf("Monto inicial: ");
    scanf("%d", &mj2);
    while(mj2>1000 || mj2<50){
        printf("Error, revise que todo este en orden\n");
        printf("Monto inicial: ");
        scanf("%d", &mj2);
    }
    printf("\n");
    
    //Mensaje de menu
    printf("Opciones: (J)ugar, (V)er apuestas, (S)alir: ");
    scanf(" %c", &opciones);
    printf("\n");
    while(opciones != 's' && opciones != 'S'){ //Va a entrar en este while mientras la opcion sea distinta a 's' o 'S'
    
        while(opciones == 'v' || opciones == 'V' ){ //Si elije VER APUESTA
            //Mensaje de monto actualizado j1 y j2
            for(int i=0; i<n1; i++){
                printf("%c", nj1[i]);
            }
            printf("\n");
            printf("Cuenta con : %d\n", mj1);
            printf("\n");
            for(int i=0; i<n2; i++){
                printf("%c", nj2[i]);
            }
            printf("\n");
            printf("Cuenta con : %d\n", mj2);
            printf("\n");
            printf("Opciones: (J)ugar, (V)er apuestas, (S)alir: ");
            scanf(" %c", &opciones);
        }
        
        while(opciones == 'j' || opciones == 'J' ){ //Si elije JUGAR
            sumaC1=0; //se resetea la variable que suma las cartas del jugador 1
            sumaC2=0; //se resetea la variable que suma las cartas del jugador 2
            cantap1=0; //se resetea la variable que suma la cantidad de apuestas del jugador 1
            cantap2=0; //se resetea la variable que suma la cantidad de apuestas del jugador 2
            apuesta1=0; //se resetea la variable que suma los aumentos de apuestas del jugador 1
            apuesta2=0; //se resetea la variable que suma los aumentos de apuestas del jugador 2
            j1termina=false; //se setea que j1 NO termina
            j2termina=false; //se setea que j2 NO termina
            j1perdio=false; //se setea que j1 NO perdio
            j2perdio=false; //se setea que j2 NO perdio
            
            //Mensaje de juego jugador 1 (pide apuesta inicial a j1)
            for(int i=0; i<n1; i++){
                printf("%c", nj1[i]);
            }
            printf(" ingresa tu apuesta inicial:");
            scanf("%d", &aumento1);
            while(aumento1>mj1 || aumento1<50){
                printf("Error, revise que todo este en orden\n");
                printf("ingresa tu apuesta inicial: ");
                scanf("%d", &aumento1);
            }
            apuesta1=aumento1;

            //Mensaje de juego jugador 2 (pide apuesta inicial a j2)
            for(int i=0; i<n2; i++){
                printf("%c", nj2[i]);
            }
            printf(" ingresa tu apuesta inicial:");
            scanf("%d", &aumento2);
            while(aumento2>mj2 || aumento2<50){
                printf("Error, revise que todo este en orden\n");
                printf("ingresa tu apuesta inicial: ");
                scanf("%d", &aumento2);
            }
            apuesta2=aumento2;

            //Mensaje de carta revelada Jugador 1
            printf("\n");
            printf("Carta de ");
            for(int j=0; j<n1; j++){
                printf("%c", nj1[j]);
            }
            printf("\n");
            num=rand()%9+1;
            sumaC1=num+sumaC1;
            printf(" ___\n");
            printf("|   |\n");
            printf("| %d |\n", num);
            printf("|___|\n");
            printf("Apuesta: %d\n", apuesta1);
            printf("Suma total: %d\n", sumaC1);
            printf("\n");

            //Mensaje de carta revelada jugador 2
            printf("\n");
            printf("Carta de ");
            for(int j=0; j<n2; j++){
                printf("%c", nj2[j]);
            }
            printf("\n");
            num=rand()%9+1;
            sumaC2= num+sumaC2;
            printf(" ___\n");
            printf("|   |\n");
            printf("| %d |\n", num);
            printf("|___|\n");
            printf("Apuesta: %d\n", apuesta2);
            printf("Suma total: %d\n", sumaC2);

            while(!j1termina || !j2termina){ //Entra a este while si j1 y j2 siguen en juego (es decir, no suman >=21 ni eligieron terminar)

                //Mensaje de aceptacion jugador 1 (pregunta si quiere seguir o terminar, en caso de seguir pregunta si quiere aumentar apuesta)
                if (!j1termina){
                    printf("\n");
                    printf("Turno de ");
                    for(int j=0; j<n1; j++){
                        printf("%c", nj1[j]);
                    }
                    printf("\n");
                    printf(" ___\n");
                    printf("|   |\n");
                    printf("| ? |\n", num);
                    printf("|___|\n");
                    printf("(J)ugar o (T)erminar\n");
                    scanf(" %c", &aceptacion);
                    while(aceptacion!='t' && aceptacion!='j' && aceptacion!='T' && aceptacion!='J'){
                        printf("Error, revise que todo este en orden\n");
                        scanf(" %c", &aceptacion);
                    }
                    switch(aceptacion){ 
                        case 't': case 'T':
                            j1termina=true;
                            break;
                        case 'j': case'J':
                            //Mensaje de aumento de apuesta jugador 1
                            if(cantap1<2){ //para que se ejecute solo si le quedan apuuestas para hacer
                                printf("En cuanto desea aumentar su apuesta?\n");
                                scanf("%i",&aumento1);
                                while (aumento1<0 || aumento1>mj1-apuesta1){
                                    printf("Error, revise que todo este en orden\n");
                                    printf("En cuanto desea aumentar su apuesta?\n");
                                    scanf("%i",&aumento1);
                                }
                                if (aumento1>0){
                                    apuesta1=apuesta1+aumento1;
                                    cantap1++;
                                }
                            }
                            break;
                        default:  printf("Error, revise que todo este en orden\n");
                            break;
                    }
                }
                
                //Mensaje de aceptacion jugador 2 (pregunta si quiere seguir o terminar, en caso de seguir pregunta si quiere aumentar apuesta)
                if (!j2termina){
                    printf("\n");
                    printf("Turno de ");
                    for(int j=0; j<n2; j++){
                        printf("%c", nj2[j]);
                    }
                    printf("\n");
                    printf(" ___\n");
                    printf("|   |\n");
                    printf("| ? |\n", num);
                    printf("|___|\n");
                    printf("(J)ugar o (T)erminar\n");
                    scanf(" %c", &aceptacion);
                    while(aceptacion!='t' && aceptacion!='j' && aceptacion!='T' && aceptacion!='J'){
                        printf("Error, revise que todo este en orden\n");
                        scanf(" %c", &aceptacion);
                    }
                    switch(aceptacion){
                        case 't': case 'T':
                            j2termina=true;
                            break;
                        case 'j': case'J':
                            //Mensaje de aumento de apuesta jugador 1
                            if(cantap2<2){ //para que se ejecute solo si le quedan apuuestas para hacer
                                printf("En cuanto desea aumentar su apuesta?\n");
                                scanf("%i",&aumento2);
                                while (aumento2<0 || aumento2>mj2-apuesta2){
                                    printf("Error, revise que todo este en orden\n");
                                    printf("En cuanto desea aumentar su apuesta?\n");
                                    scanf("%i",&aumento2);
                                }
                                if (aumento2>0){
                                    apuesta2=apuesta2+aumento2;
                                    cantap2++;
                                }
                            }
                            break;
                        default:  printf("Error, revise que todo este en orden\n");
                            break;
                    }
                }

                //Mensaje de carta revelada jugador 1. Se ejecuta siempre que j1 este jugando.
                if(!j1termina){
                    printf("\n");
                    printf("Carta de ");
                    for(int j=0; j<n1; j++){
                        printf("%c", nj1[j]);
                    }
                    printf("\n");
                    num=rand()%9+1;
                    sumaC1= num+sumaC1;
                    printf(" ___\n");
                    printf("|   |\n");
                    printf("| %d |\n", num);
                    printf("|___|\n");
                    printf("Apuesta: %d\n", apuesta1);
                    printf("Suma total: %d\n", sumaC1);
                }
                if(sumaC1==21){ //j1 gana
                    j1termina=true;
                }
                if(sumaC1>21){ //j1 pierde
                    j1termina=true;
                    j1perdio=true;
                }

                //Mensaje de carta revelada jugador 2. Se ejecuta siempre que j2 este jugando
                if(!j2termina){
                    printf("\n");
                    printf("Carta de ");
                    for(int j=0; j<n2; j++){
                        printf("%c", nj2[j]);
                    }
                    printf("\n");
                    num=rand()%9+1;
                    sumaC2= num+sumaC2;
                    printf(" ___\n");
                    printf("|   |\n");
                    printf("| %d |\n", num);
                    printf("|___|\n");
                    printf("Apuesta: %d\n", apuesta2);
                    printf("Suma total: %d\n", sumaC2);
                    printf("\n");
                }

                if(sumaC2==21){ //j2 gana
                    j2termina=true;
                }
                if(sumaC2>21){ //j2 pierde
                    j2termina=true;
                    j2perdio=true;
                }
            }

            //Mensaje del croupier
            sumaCr=0;
            printf("\n");
            printf("Ahora juega el Croupier\n");
            printf("\n");
            num=rand()%9+1;
            sumaCr=num;
            printf(" ___\n");
            printf("|   |\n");
            printf("| %d |\n", num);
            printf("|___|\n");
            printf("Suma total: %d\n",num);

            while(sumaCr<15){ // El Cropuier va a sacar hasta tener mas de 15.
                printf("Decido tomar una carta mas.\n"); 
                printf("\n");
                num=rand()%9+1;
                sumaCr= sumaCr +num;
                printf(" ___\n");
                printf("|   |\n");
                printf("| %d |\n", num);
                printf("|___|\n");
                printf("Suma total: %d\n",sumaCr);
            } 

            if (!j1perdio || !j2perdio) { //Entra si hay al menos uno de los jugadores que no perdio
                while (sumaCr<sumaC1 && sumaCr<sumaC2){ // El Cropuier va a sacar hasta tener mas que, al menos, uno de los jugadores
                    printf("Decido tomar una carta mas.\n");
                    printf("\n");
                    num=rand()%9+1;
                    sumaCr= sumaCr +num;
                    printf(" ___\n");
                    printf("|   |\n");
                    printf("| %d |\n", num);
                    printf("|___|\n");
                    printf("Suma total: %d\n",sumaCr);
                }
                if (sumaC1>sumaCr || sumaC2>sumaCr){  // Si le gana a un jugador pero pierde con otro, por decision al azar elige si sacar otra carta o no.
                    otracarta=rand()%2;
                    if(otracarta==0){
                        printf("\n");
                        num=rand()%9+1;
                        sumaCr=sumaCr + num;
                        printf(" ___\n");
                        printf("|   |\n");
                        printf("| %d |\n", num);
                        printf("|___|\n");
                        printf("Suma total: %d\n",sumaCr);
                    }
                    else 
                        printf("El Croupier decide no sacar mas cartas. \n");
                }

            }

            // Fase de pago de apuestas
            printf("\n");
            printf(".--------------------------------------. \n");
            printf(".--------------------------------------. \n");
            printf(".--------------------------------------. \n");
            printf(".--------------------------------------. \n");
            printf(".-------Fase de Pago de Apuestas-------. \n");
            printf(".--------------------------------------. \n");
            printf(".--------------------------------------. \n");
            printf(".--------------------------------------. \n");
            printf("\n");
            printf("Suma total del croupier: %d \n",sumaCr);

            for(int i=0; i<n1; i++){ //suma final del jugador 1
                    printf("%c", nj1[i]);
                }
                printf(" suma: %d\n", sumaC1);

            for(int i=0; i<n2; i++){ //suma final del jugador 2
                    printf("%c", nj2[i]);
                }
                printf(" suma: %d\n", sumaC2);

   
            if(j1perdio){ //si j1 suma mas de 21
                for(int i=0; i<n1; i++){
                    printf("%c", nj1[i]);
                }
                printf(" pierde\n");
                mj1=mj1-apuesta1;
            }  
            if(j2perdio){ //si j2 suma mas de 21
                for(int i=0; i<n2; i++){
                    printf("%c", nj2[i]);
                }
                printf(" pierde\n");
                mj2=mj2-apuesta2;
            }

            if (sumaC1==21){ //si j1 suma 21 (gana)
                for(int j=0; j<n1; j++){
                    printf("%c", nj1[j]);
                }
                printf(" gana\n");
                j1perdio=true; //se setea en 'true' para que no entre en los siguientes 'if'
                mj1=mj1+(apuesta1*2);
            }
            if(sumaC2==21){ //si j2 suma 21 (gana)
                for(int i=0; i<n2; i++){
                    printf("%c", nj2[i]);
                }
                printf(" gana\n");
                j2perdio=true; //se setea en 'true' para que no entre en los siguientes 'if'
                mj2=mj2+(apuesta2*2);
            }

            if(sumaCr>21) { //Si croupier suma mas que 21, osea pierde el juego, duplica las apuestas de los jugadores que no se pasaron de 21
                if(!j1perdio){ //si j1 no se paso de 21
                   printf("Croupier se paso de 21, ");
                   for(int i=0; i<n1; i++){
                        printf("%c", nj1[i]);
                    }
                    printf(" gana\n");
                    mj1=mj1+apuesta1; //suma el doble de la apuesta al monto del jugador 1
                    j1perdio=true;
                }   
                if(!j2perdio){ //si j2 no se paso de 21
                    printf("Croupier se paso de 21, ");
                    for(int i=0; i<n2; i++){
                        printf("%c", nj2[i]);
                    }
                    printf(" gana\n");
                    mj2=mj2+apuesta2; //suma el doble de la apuesta al monto del jugador 2
                    j2perdio=true;
                }    
            }

            if(sumaC1>sumaCr && !j1perdio){ //j1 no se paso de 21 y supera al croupier 
                for(int j=0; j<n1; j++){
                    printf("%c", nj1[j]);
                }
                printf(" gana\n");
                mj1=mj1+apuesta1;
            }    
            if(sumaC1<=sumaCr && !j1perdio && sumaCr<22){ //j1 no se paso de 21 pero no supera al croupier, que tampoco se paso de 21
                for(int j=0; j<n1; j++){
                    printf("%c", nj1[j]);
                }
                printf(" pierde\n");
                mj1=mj1-apuesta1;
            }

            if(sumaC2>sumaCr && !j2perdio){ //j2 no se paso de 21 y supera al croupier
                for(int i=0; i<n2; i++){
                    printf("%c", nj2[i]);
                }
                printf(" gana\n");
                mj2=mj2+apuesta2;
            }
            if(sumaC2<=sumaCr && !j2perdio && sumaCr<22){ //j2 no se paso de 21 pero no supera al croupier, que tampoco se paso de 21
                for(int i=0; i<n2; i++){
                    printf("%c", nj2[i]);
                }
                printf(" pierde\n");//si j2 pierde con croupier
                mj2=mj2-apuesta2;
            }
        
            //Mensaje de monto actualizado j1 y j2
            printf("\n");
            for(int i=0; i<n1; i++){
                printf("%c", nj1[i]);
            }
            printf("\n");
            printf("Cuenta con : %d\n", mj1);
            printf("\n");
            for(int i=0; i<n2; i++){
                printf("%c", nj2[i]);
            }
            printf("\n");
            printf("Cuenta con : %d\n", mj2);
            printf("\n");
            printf("Opciones: (J)ugar, (V)er apuestas, (S)alir: ");
            scanf(" %c", &opciones);
        }
    }
    //mensaje de despedida
    if(opciones == 's' || opciones  == 'S')
    printf("Nos vemos, que vuelvan pronto\n");
   
    return 0;
}
       
