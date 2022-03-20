#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombre[60];
	char apellido[60];
	char direccion[60];
	int telefono;
};

 void ingresar_estudiante();
 void abrir_estudiante();
 //void buscar_codigo();
 
int main (){
	abrir_estudiante();
    ingresar_estudiante();
	return 0;	
}

void buscar_codigo(){
		FILE* archivo = fopen(nombe_archivo,"rb");	
	int /*pos=0indice=0,*/cod=0;
	cout<<"INGRESE CODIGO DEL ESTUDIANTE: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
		
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Direccion:"<<estudiante.direccion<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}

void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"****************************************************************************"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<"| "<<"DIRECCION"<<" | "<<"TELEFONO"<<" | "<<endl;	
		do{
		cout<<"________________________________________________________________________"<<endl;
		cout << registro <<" | "<< estudiante.codigo <<"  |  "<< estudiante.nombre<<" "<<estudiante.apellido<<" | "<< estudiante.direccion<<" | "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
	
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese direccion:";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre si/no : ";
		cin>>continuar;
		} while((continuar=='si') || (continuar=='SI') );
		
	
	fclose(archivo);
	abrir_estudiante();	
	buscar_codigo();
}

