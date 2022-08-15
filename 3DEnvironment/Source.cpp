#include <iostream>
//==================================
#include "Header.h"
//#define _CRT_SECURE_NO_WARNINGS

void laodRoom();
void calcular();

bool loadedRoom;
room r; //Room
source s;   //Fuente
receptor re; //Receptor
reflection* ry; //Reflexion

vector1** vis_vector;   //Vectores para visualizacion
double ** vis_modvec;   //Distancia acumulativa para animacion de la propagacion
int ** vis_timacu;      //Tiempo de vuelo de los vectores



int NumTri = 0;
matInt matTime; //Matriz tiempo
matDouble matAngulos; //Matriz Angulos
MatEnergia mE;  //Matriz de Energia: Energia vs tiempo
matDouble matDist;

matDouble matPorcentaje; //Matriz Porcentaje


//--Receptor
double * arrayAngulosR;         //Angulos Receptor
int *   arrayTimeR;               //Tempo receptor 
double * arrayPorcentajeR;      //Tempo receptor 

matDouble   matAngulosR;
matDouble   matPorcentajeR;
matInt      matTimeR;









int main(){
    laodRoom();
    calcular();

    return 0;
}

void laodRoom() {
    if (!loadedRoom) {
        int nDivTri;
        nDivTri = 2;
        r.Init();
        r.NewPlanes(6);// Geneara 6 planos
        //square back
        r.p[0].NewPoints(4);// Gnererar los 4 puntos

        r.p[0].p[0].x = -2.0f;
        r.p[0].p[0].y = 2.0f;
        r.p[0].p[0].z = 2.0f;

        r.p[0].p[1].x = -2.0f;
        r.p[0].p[1].y = -2.0f;
        r.p[0].p[1].z = 2.0f;

        r.p[0].p[2].x = -2.0f;
        r.p[0].p[2].y = -2.0f;
        r.p[0].p[2].z = -2.0f;

        r.p[0].p[3].x = -2.0f;
        r.p[0].p[3].y = 2.0f;
        r.p[0].p[3].z = -2.0f;

        //r.p[0].PointGenTriangle();
        r.p[0].MoreTriangle(nDivTri);



        //square front
        r.p[1].NewPoints(4);// Gnererar los 4 puntos

        r.p[1].p[0].x = 2.0f;
        r.p[1].p[0].y = 2.0f;
        r.p[1].p[0].z = 2.0f;

        r.p[1].p[1].x = 2.0f;
        r.p[1].p[1].y = 2.0f;
        r.p[1].p[1].z = -2.0f;

        r.p[1].p[2].x = 2.0f;
        r.p[1].p[2].y = -2.0f;
        r.p[1].p[2].z = -2.0f;

        r.p[1].p[3].x = 2.0f;
        r.p[1].p[3].y = -2.0f;
        r.p[1].p[3].z = 2.0f;

        r.p[1].MoreTriangle(nDivTri);

        //square left
        r.p[2].NewPoints(4);

        r.p[2].p[0].x = -2.0f;
        r.p[2].p[0].y = -2.0f;
        r.p[2].p[0].z = 2.0f;

        r.p[2].p[1].x = 2.0f;
        r.p[2].p[1].y = -2.0f;
        r.p[2].p[1].z = 2.0f;

        r.p[2].p[2].x = 2.0f;
        r.p[2].p[2].y = -2.0f;
        r.p[2].p[2].z = -2.0f;

        r.p[2].p[3].x = -2.0f;
        r.p[2].p[3].y = -2.0f;
        r.p[2].p[3].z = -2.0f;
        r.p[2].MoreTriangle(nDivTri);

        //square right
        r.p[3].NewPoints(4);// Gnererar los 4 puntos

        r.p[3].p[0].x = 2.0f;
        r.p[3].p[0].y = 2.0f;
        r.p[3].p[0].z = 2.0f;

        r.p[3].p[1].x = -2.0f;
        r.p[3].p[1].y = 2.0f;
        r.p[3].p[1].z = 2.0f;

        r.p[3].p[2].x = -2.0f;
        r.p[3].p[2].y = 2.0f;
        r.p[3].p[2].z = -2.0f;

        r.p[3].p[3].x = 2.0f;
        r.p[3].p[3].y = 2.0f;
        r.p[3].p[3].z = -2.0f;
        r.p[3].MoreTriangle(nDivTri);


        //square top
        r.p[4].NewPoints(4);

        r.p[4].p[0].x = -2.0f;
        r.p[4].p[0].y = -2.0f;
        r.p[4].p[0].z = 2.0f;

        r.p[4].p[1].x = -2.0f;
        r.p[4].p[1].y = 2.0f;
        r.p[4].p[1].z = 2.0f;

        r.p[4].p[2].x = 2.0f;
        r.p[4].p[2].y = 2.0f;
        r.p[4].p[2].z = 2.0f;

        r.p[4].p[3].x = 2.0f;
        r.p[4].p[3].y = -2.0f;
        r.p[4].p[3].z = 2.0f;
        r.p[4].MoreTriangle(nDivTri);

        //square bottom
        r.p[5].NewPoints(4);

        r.p[5].p[0].x = -2.0f;
        r.p[5].p[0].y = 2.0f;
        r.p[5].p[0].z = -2.0f;

        r.p[5].p[1].x = -2.0f;
        r.p[5].p[1].y = -2.0f;
        r.p[5].p[1].z = -2.0f;

        r.p[5].p[2].x = 2.0f;
        r.p[5].p[2].y = -2.0f;
        r.p[5].p[2].z = -2.0f;

        r.p[5].p[3].x = 2.0f;
        r.p[5].p[3].y = 2.0f;
        r.p[5].p[3].z = -2.0f;
        r.p[5].MoreTriangle(nDivTri);


        //Calcular los normales del plano
        int cont_t = 0;// contador de triangulos de la sala
        for (int i = 0; i < r.NP; i++) {
            r.p[i].n = NormalPlano(r.p[i]);
            for (int j = 0; j < r.p[i].NT; j++) {
                r.p[i].t[j].CalculateProjection();
                r.p[i].t[j].Centroid();
                r.p[i].t[j].ID = cont_t;
                cont_t++;
            }

        }

        NumTri = cont_t;
        //numRec = 27;

        


        /////////////////////////////////////////////
        //re.p.x = 1.0;
        //re.p.x = 0.0;
        //re.p.x = 0.0;


        matDist.init(NumTri, NumTri);
        matAngulos.init(NumTri, NumTri);
        matTime.init(NumTri, NumTri);




        double* areaT;
        areaT = NULL;
        areaT = new double[NumTri];

        for (int i = 0; i < NumTri;i++) {
            areaT[i] = 0.0;
        }

        //array init receptor
        arrayAngulosR = NULL;
        arrayAngulosR = new double[NumTri];

        arrayTimeR = NULL;
        arrayTimeR = new int[durSim];

        for (int i = 0; i < durSim;i++) {
            arrayTimeR[i] = 0;
        }

        double areaTRecp = 0.0;

        //Receptor init
        matAngulosR.init(r.NR, NumTri);
        matTimeR.init(r.NR, NumTri);



      
        
        int ID_Tri_1, ID_Tri_2; //Id triangulos
        point BC_Tri_1, BC_Tri_2; // Baricentro triangulos

        for (int i = 0;i < r.NP;i++) { //Recorre los planos

            for (int j = 0;j < r.p[i].NT;j++) {// recorre los triangulos

                //r.p[i].t[j].bc; //Primer Baricentro
                ID_Tri_1 = r.p[i].t[j].ID; //triangulo de partida
                BC_Tri_1 = r.p[i].t[j].bc;

                //Receptor
                //arrayTimeR[ID_Tri_1] = int(1000 * BC_Tri_1.distancia(re.p) / V_SON);
                //arrayAngulosR[ID_Tri_1] = re.solidAngle(BC_Tri_1);
                //areaTRecp += arrayAngulosR[ID_Tri_1];
                for (int indRecp = 0;indRecp < r.NR;indRecp++) {
                    matTimeR.i[indRecp][ID_Tri_1] = int(1000 * BC_Tri_1.distancia(r.r[indRecp].p) / V_SON);
                    matAngulosR.d[indRecp][ID_Tri_1] = re.solidAngle(BC_Tri_1);
                }

                //Triangulos
                for (int k = 0; k < r.NP; k++) {
                    

                    for (int l = 0; l < r.p[k].NT; l++) {
                        //r.p[k].t[l].bc; //Segundo Baricentro
                        ID_Tri_2 = r.p[k].t[l].ID; // triangulo de llegad
                        BC_Tri_2 = r.p[k].t[l].bc;

                        if (i != k) {
                            //matDist.d[r.p[i].t[j].ID][r.p[k].t[l].ID] = r.p[i].t[j].bc.distancia(r.p[k].t[l].bc);   
                            matDist.d[ID_Tri_1][ID_Tri_2] = BC_Tri_1.distancia(BC_Tri_2);

                            matTime.i[ID_Tri_1][ID_Tri_2] = int(1000 * matDist.d[ID_Tri_1][ID_Tri_2] / V_SON);


                            matAngulos.d[ID_Tri_1][ID_Tri_2] = r.p[k].t[l].solidAngle(BC_Tri_1);

                            areaT[ID_Tri_1] += matAngulos.d[ID_Tri_1][ID_Tri_2];
                        }

                        else {
                            matDist.d[r.p[i].t[j].ID][r.p[k].t[l].ID] = 0.0;

                            matTime.i[ID_Tri_1][ID_Tri_2] = 0;

                            matAngulos.d[ID_Tri_1][ID_Tri_2] = 0.0;
                        }
                    }
                }
            }
        }


        //Inicializar 
        matPorcentaje.init(NumTri, NumTri);
        matPorcentajeR.init(r.NR, NumTri);

        //arrayPorcentajeR = NULL;
        //arrayPorcentajeR = new double[NumTri];

        //Calculo de matriz porcentaje y porcentaje de receptores
        for (int i = 0;i < NumTri;i++) {
            //arrayPorcentajeR[i] = arrayAngulosR[i] / areaT[i];

            for (int j = 0;j < NumTri;j++) {
                matPorcentaje.d[i][j] = matAngulos.d[i][j] / areaT[i];
            }
        }

        for (int indRecp = 0; indRecp < r.NR; indRecp++) {
            for (int indTri = 0; indTri < NumTri; indTri++) {
                matPorcentajeR.d[indRecp][indTri] = matAngulosR.d[indRecp][indTri] / areaT[indTri];

            }
        }

    
        matTime.grabarArchivo('T', NumTri);
        matDist.grabarArchivo('D', NumTri);
        matAngulos.grabarArchivo('P', NumTri);


        matTime.grabarArchivo('TR', NumTri);
        matAngulos.grabarArchivo('PR', NumTri);

       
    }


    
}

void  calcular() {
    //  re  -> receptor
    //  s   -> fuente
    //  r   -> room
    //  mE  -> Matriz de energia
    //  ef  -> Enegia inicial de la fuente

    double eneRay;  //  Energía del Rayo
    double eneRes; //   Energía Residual


    for (int indRecp = 0; indRecp < r.NR; ++indRecp) {
        r.r[indRecp].createTimeSamples(durSim); //Inicializa el array de energia del receptor
    }
    s.eF = 100;

    s.createRays(numRay); // Crea los rayos

    eneRay = s.eF / s.NRAYS;

    ry = NULL;
    ry = r.RayTracing(s.p, s.Rays, s.NRAYS); // Calculo del trazado de rayos

    mE.init(NumTri, durSim); //Inicializa la matriz con ceros

    vis_vector = new vector1 * [s.NRAYS];
    vis_modvec = new double* [s.NRAYS];
    vis_timacu = new int* [s.NRAYS];

    double alfa;    //Coeficiente de absorcion
    double delta;   //Coeficiente de difusion
    alfa = 0.2;
    delta = 0.15;

    for (int R = 0; R < s.NRAYS; R++) {

        eneRes = eneRay; //Inicializo energía residual

        //Definimos la primera dimension (# de rayos)
        vis_vector[R] = new vector1[ry[R].N - 1];
        vis_modvec[R] = new double[ry[R].N];
        vis_timacu[R] = new int[ry[R].N];

        vis_modvec[R][0] = 0.0;
        vis_timacu[R][0] = 0.0;

        // Recorrer las reflexiones en cada rayo
        for (int i = 0; i < ry[R].N - 1; i++) {
            //Guardo el vector con la ruta de la reflexion
            vis_vector[R][i] = ry[R].r[i + 1] - ry[R].r[i];

            //Registro la distancia acumulada de las reflexiones anteriores
            vis_modvec[R][i + 1] = vis_modvec[R][i] + ry[R].d[i + 1];
            vis_timacu[R][i + 1] = int((1000 * vis_modvec[R][i + 1] / V_SON));
        }

        //Captacion en recpetor de reflexiones especulares y carga de la matriz de energia difusa
        for (int i = 1; i < ry[R].N; i++) {

            //-- Indices apra recorrer la matriz de energia
            int indTri; //indice de triangulo
            int indTime; //indice de tiempo


            indTri = ry[R].idTriangle[i];
            indTime = vis_timacu[R][i];     //instancias de tiempo donde se produjo el choque

            mE.energia[indTri][indTime] += (eneRes * (1 - alfa) * delta); //Cragar la matriz con la energia difusa

            for (int indRecp = 0; indRecp < r.NR; ++indRecp) {
                r.r[indRecp].receptionRayTracing(ry[R].r[i - 1], vis_vector[R][i - 1], vis_timacu[R][i], r.maxd, eneRes);
             
            }

            //estamos actualizando la energia residual del rayo la energia que le queda.
            eneRes = eneRes * (1 - alfa) * (1 - delta); //energia reflejada especularmente
        }
    }


          


    //Distrubucion de la energia difusa segun la matriz porcentaje
    for (int indTime = 0; indTime < durSim; indTime++) {
        for (int indTriOrig = 0; indTriOrig < NumTri; indTriOrig++) {
            for (int indTriDest = 0; indTriDest < NumTri; indTriDest++) {
                int tVuelo = indTime + matTime.i[indTriOrig][indTriDest];
                if (tVuelo < durSim) {
                    mE.energia[indTriDest][tVuelo] += mE.energia[indTriOrig][indTime] * matPorcentaje.d[indTriOrig][indTriDest] * (1 - alfa);
                }
            }


            for (int indRecp = 0; indRecp < r.NR; indRecp++) {
                int tVueloRecep = indTime + matTimeR.i[indRecp][indTriOrig];
                if (tVueloRecep < durSim) {
                    r.r[indRecp].eR[tVueloRecep] += mE.energia[indTriOrig][indTime] * matAngulosR.d[indRecp][indTriOrig];
                }
            }

        }
    }
    
    //Guardar Data del Receptor
    for (int indRecp = 0; indRecp < r.NR; indRecp++) {
        r.r[indRecp].grabarArchivo();
    }
    

}