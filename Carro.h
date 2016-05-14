typedef struct{
	int carCordX[3000000]; 
	int carCordY[3000000];
	int cont_cars;
}Car;


/*
Create de coordenates of car
*/
void  CreateEnemyCar(Car *car, int numberOfCars)
{
    int x;
    for(x=1;x<=numberOfCars;x++){
        switch(numberOfCars){
            case 1:
                car->carCordX[car->cont_cars+1]=(rand()%27)+1;
                break;

            case 2:
                if(x==1){
                    car->carCordX[car->cont_cars+1]=(rand()%14)+1;
                }else{
                    car->carCordX[car->cont_cars+1]=(rand()%12)+15;
                }
                break;

            case 3:
                if(x==1){
                    car->carCordX[car->cont_cars+1]=(rand()%8)+1;
                }
                if(x==2){
                    car->carCordX[car->cont_cars+1]=(rand()%8)+10;
                }
                if(x==3){
                    car->carCordX[car->cont_cars+1]=(rand()%7)+20; 
                }
                break;
        }
    	
    	car->carCordY[car->cont_cars+1]=2;
    	car->carCordX[car->cont_cars+2]=car->carCordX[car->cont_cars+1]+2;
    	car->carCordY[car->cont_cars+2]=2;
    	car->carCordX[car->cont_cars+3]=car->carCordX[car->cont_cars+1]+1;
    	car->carCordY[car->cont_cars+3]=3;
    	car->carCordX[car->cont_cars+4]=car->carCordX[car->cont_cars+1];
    	car->carCordY[car->cont_cars+4]=4;
    	car->carCordX[car->cont_cars+5]=car->carCordX[car->cont_cars+1]+2;
    	car->carCordY[car->cont_cars+5]=4;
    	car->cont_cars+=5;
    }
}


/*
Move the enemy car
*/
void MoveEnemyCar(Car  *car){

	int i, center_string;

    center_string = 0;

     for(i=1;i<=car->cont_cars;i++){
     		
         if(car->carCordY[i]<=55){
 
                center_string++;
                
                if(car->carCordY[i]!=55){
                 	mgotoxy(car->carCordX[i],car->carCordY[i]);
                 	printf(" ");
             	}
                
                if(car->carCordY[i]==50)
                 	car->carCordY[i]=55;

                if(car->carCordY[i]<=50){
		             
		             car->carCordY[i]++;
		             mgotoxy(car->carCordX[i],car->carCordY[i]);
		            
		             if(center_string==3){
		               printf("%c",219);
		             }else{
		                printf("%c",1);
		             }

             	}
                
                if(center_string==5)
                	center_string=0;
        }

	}  
} 
             