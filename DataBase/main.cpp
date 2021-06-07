//
//  main.cpp
//  DataBase
//
//  Created by Jonathan Emmanuell Vázquez González on 06/06/21.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define ASCENDENTE 0u
#define DESENDENTE 1u

using namespace std;

typedef struct Informacion
{
    std::string artista;
    int numTracks;
    float calificacion;
} Informacion;

typedef struct Album
{
    std::string nombre;
    Informacion info;
}Album;

class Disco
{
private:
    int id_key;
    Album *cd;
    
public:
    Disco()
    {
        cd = new Album;
    }
    
    ~Disco()
    {
        delete cd;
    }
    
    int GetIdKey(void)
    {
        return id_key;
    }
    
    void SetIdKey(int id)
    {
        this->id_key = id;
    }
    
    Album *GetCD(void)
    {
        return cd;
    }
    
    void SetCD(Album *_cd)
    {
        cd->nombre = _cd->nombre;
        cd->info.artista = _cd->info.artista;
        cd->info.calificacion = _cd->info.calificacion;
        cd->info.numTracks = _cd->info.numTracks;
    }
    
    void SetInfo(int _id, Album *_cd)
    {
        SetIdKey(_id);
        SetCD(_cd);
    }
};

class Database
{
private:
    int size;
    Disco *data;

public:
    Database()
    {
        size = 0;
        data = NULL;
    }
    
    ~Database()
    {
        delete [] data;
        data = NULL;
        size = 0;
    }
    
    int GetSize(void)
    {
        return  size;
    }
    
    void SetSize(int _size)
    {
        size = _size;
    }
    
    void ReservarMemoria(void)
    {
        data = new Disco [size];
    }
    
    void Escribir(void);
    void Mostrar(void);
    void OrdenarNumericamente(unsigned char type);
    void OrdenarNumDesendente(void);
    void OrdenarNumAsendente(void);
    void OrdenarAlfabeticamente(void);
    void GenerarAchivo(void);
    
};

void Database::Escribir(void)
{
    int i = 0;
    Album aux;
    
    for(i = 0; i < this->size; i++)
    {
        std::cout << "Nombre del album: ";
        std::cin >> aux.nombre;
        
        std::cout << "Nombre del artista: ";
        std::cin >> aux.info.artista;
        
        std::cout << "Nombre del numero de tracks: ";
        std::cin >> aux.info.numTracks;
        
        std::cout << "Nombre del calificacion: ";
        std::cin >> aux.info.calificacion;
        
        this->data[i].SetIdKey(i);
        this->data[i].SetCD(&aux);
        
        std::cout << "*******************************************************************" << std::endl;
    }
}

void Database::Mostrar(void)
{
    int i = 0;
    Album *aux = NULL;
    
    for(i = 0; i < this->size; i++)
    {
        std::cout << "ID database: " << this->data[i].GetIdKey() << std::endl;
        aux = this->data[i].GetCD();
        
        std::cout << "Nombre del album: " << aux->nombre << std::endl;
        std::cout << "Nombre del artista: " << aux->info.artista << std::endl;
        std::cout << "Nombre del calification: " << aux->info.calificacion << std::endl;
        std::cout << "Nombre del numero de pistas: " << aux->info.numTracks << std::endl;
        
        std::cout << "*******************************************************************" << std::endl;
    }
}

void Database::OrdenarNumDesendente(void)
{
    int i = 0;
    int j = 0;
    int idi = 0;
    int idj = 0;
    int idaux = 0;
    Album *aux = NULL;
    Album ax2;
    
    std::cout << "\n\ntamanio: " << this->size << std::endl;

    for(i = 0; i < this->size - 1; i++)
    {
        idi = data[i].GetIdKey();
        for(j = i + 1; j < this->size; j++)
        {
            idj = data[j].GetIdKey();
            
            if(idi < idj)
            {
                std::cout << "Ordenando Elementos!!!!!" << std::endl;
                idaux = idi;
                idi = idj;
                idj = idaux;
                
                data[i].SetIdKey(idi);
                data[j].SetIdKey(idj);
                
                aux = data[i].GetCD();
                
                ax2.nombre = aux->nombre;
                ax2.info.artista = aux->info.artista;
                ax2.info.calificacion = aux->info.calificacion;
                ax2.info.numTracks = aux->info.numTracks;
                
                data[i].SetCD(data[j].GetCD());
                data[j].SetCD(&ax2);
            }
            else
            {
                std::cout << "Elemento bien posicionado!!!!!" << std::endl;
            }
        }
    }
}

void Database::OrdenarNumAsendente(void)
{
    
}

void Database::OrdenarNumericamente(unsigned char type)
{
    switch (type) {
        case ASCENDENTE:
            OrdenarNumAsendente();
            break;
        case DESENDENTE:
            OrdenarNumDesendente();
            break;
            
        default:
            std::cout << "Ordenamiento no soportado!!!" << std::endl;
            break;
    }
}

void Database::OrdenarAlfabeticamente(){
    int i=0;
    int j =0;
    int idi, idj, idaux;
    string albumi,albumi2;
    Album *aux=NULL;
    Album *aux2=NULL;
    Album ax3;
    
    for (i = 0; i < this->size - 1; i++)
    {
        for(j = i + 1; j < this->size; j++)
        {
            idi = data[i].GetIdKey();
            idj=data[j].GetIdKey();
            
            aux = data[i].GetCD();
            albumi= aux->nombre;
            
            aux2 = data[j].GetCD();
            albumi2= aux2->nombre;
            if (albumi.compare(albumi2)>0)
            {
                idaux=idi;
                idi=idj;
                idj=idaux;
                
                data[i].SetIdKey(idi);
                data[j].SetIdKey(idj);
                
                ax3.nombre=aux->nombre;
                ax3.info.artista=aux->info.artista;
                ax3.info.calificacion=aux->info.calificacion;
                ax3.info.numTracks=aux->info.numTracks;
                
                data[i].SetCD(data[j].GetCD());
                data[j].SetCD(&ax3);
                
            }
        }
    }
}

void Database::GenerarAchivo(){
    int idi,i=0;
    Album *aux=NULL;
    Album aux2;
    
<<<<<<< HEAD
    int numtracks;
=======
    int Id=0,numtracks;
>>>>>>> 0a633d1df0f7c48dc81d886127d66ea5c7d14ecf
    string nombre,artista;
    float calificacion;
    
    
<<<<<<< HEAD
    FILE *archivo = NULL;
    archivo=fopen("./BasedeDatos.txt", "wt");
    
    if(NULL != archivo)
    {
        for (i=0; i<this->size; i++)
        {
            idi=data[i].GetIdKey();
            aux=data[i].GetCD();
            
            nombre=aux->nombre;
            artista=aux->info.artista;
            numtracks=aux->info.numTracks;
            calificacion=aux->info.calificacion;
            
            fprintf(archivo, "%d %s %s %d %f",idi,nombre.c_str(),artista.c_str(),numtracks,calificacion);
        }
            
        fclose(archivo);
    }
    else
    {
        cout << "Error al generar el archivo!!\n" << endl;
    }
    
    cout << "Proceso terminado" << endl;
}
=======
    FILE *archivo;
    archivo=fopen("BasedeDatos.txt", "wt");
    
    
    for (i=0; i<this->size; i++) {
        
        idi=data[i].GetIdKey();
        aux=data[i].GetCD();
        
        nombre=aux->nombre;
        artista=aux->info.artista;
        numtracks=aux->info.numTracks;
        calificacion=aux->info.calificacion;
        
        fprintf(archivo, "%d %s %s %d %f",idi,nombre.c_str(),artista.c_str(),numtracks,calificacion);
    }
    fclose(archivo);
    cout<<"Proceso terminado";
    }

>>>>>>> 0a633d1df0f7c48dc81d886127d66ea5c7d14ecf

int main(int argc, const char * argv[]) {
    int size = 0;
    Database db;
    
    std::cout << "Database size: " << db.GetSize() << std::endl;
    std::cout << "Ingrese el total de datos: ";
    std::cin >> size;
    
    db.SetSize(size);
    db.ReservarMemoria();
    
    std::cout << "Database size: " << db.GetSize() << std::endl;
    
    db.Escribir();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    db.Mostrar();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "---------------------------- Ordenamiento ---------------------------" << std::endl;
    //db.OrdenarNumericamente(DESENDENTE);
<<<<<<< HEAD
    //db.OrdenarAlfabeticamente();
=======
    db.OrdenarAlfabeticamente();
>>>>>>> 0a633d1df0f7c48dc81d886127d66ea5c7d14ecf
    db.GenerarAchivo();
    std::cout << "---------------------------------------------------------------------" << std::endl;
    //db.Mostrar();
    
    std::cout << "Hello, World!\n";
    return 0;
}
