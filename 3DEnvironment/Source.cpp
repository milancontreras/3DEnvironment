#include <iostream>
//==================================
#include "Header.h"
//#define _CRT_SECURE_NO_WARNINGS

void laodRoom();

bool loadedRoom;
room r;
source s;
receptor re;
reflection* ry;

vector1** vis_vector;
double ** vis_modvec;
int **vis_timacu;



int NumTri = 0;
matInt matTime; //Matriz tiempo
matDouble matAngulos;
MatEnergia mE;




int main(){
    laodRoom();
    return 0;
}

void laodRoom() {
    if (!loadedRoom) {
        int nDivTri;
        nDivTri = 2;
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

        r.p[0].PointGenTriangle();
        //r.p[0].MoreTriangle(nDivTri);



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
        int cont_t = 0;// contador de triangulos
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

        matDouble matDist;

        matDist.init(NumTri, NumTri);
        matAngulos.init(NumTri, NumTri);
        matTime.init(NumTri, NumTri);

        double* areaT;
        areaT = NULL;
        areaT = new double[NumTri];

        for (int i = 0; i < NumTri;i++) {
            areaT[i] = 0.0;
        }


      
        
        int ID_Tri_1, ID_Tri_2; //Id triangulos
        point BC_Tri_1, BC_Tri_2; // Baricentro triangulos

        for (int i = 0;i < r.NP;i++) {
            for (int j = 0;j < r.p[i].NT;j++) {
                //r.p[i].t[j].bc; //Primer Baricentro
                ID_Tri_1 = r.p[i].t[j].ID; //triangulo de partida
                BC_Tri_1 = r.p[i].t[j].bc;
                for (int k = 0; k < r.NP; k++) {
                    for (int l = 0; l < r.p[k].NT; l++) {
                        //r.p[k].t[l].bc; //Segundo Baricentro
                        ID_Tri_2 = r.p[k].t[l].ID; // triangulo de llegad
                        BC_Tri_2 = r.p[k].t[l].bc;

                        if (i != k) {
                            //matDist.d[r.p[i].t[j].ID][r.p[k].t[l].ID] = r.p[i].t[j].bc.distancia(r.p[k].t[l].bc);   
                            matDist.d[ID_Tri_1][ID_Tri_2] = BC_Tri_1.distancia(BC_Tri_2);

                            matTime.i[ID_Tri_1][ID_Tri_2] = int(1000 * matDist.d[ID_Tri_1][ID_Tri_1] / V_SON);

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



        for (int i = 0;i < NumTri;i++) {
            for (int j = 0;j < NumTri;j++) {
                matAngulos.d[i][j] = matAngulos.d[i][j] / areaT[i];
            }
        }

        



        
        matTime.grabarArchivo('T', NumTri);
        matDist.grabarArchivo('D', NumTri);
        matAngulos.grabarArchivo('P', NumTri);

    }


    
}

void  calcular() {
    double eneRay, eneRes; //Energía del rayo y energía residual
    //durSim = 1000; //Duración de la simulación (1 seg o 1000 miliseg)
    re.createTimeSamples(durSim);
    s.eF = 100;
    s.createRays(numRay);
    //edRayos->Text = s.NRAYS;

    eneRay = s.eF / s.NRAYS;

    ry = NULL;
    ry = r.RayTracing(s.p, s.Rays, s.NRAYS);

    mE.init(NumTri, durSim);
    //mEN.init(numTri, durSim);

    vis_vector = new vector1 * [s.NRAYS];
    vis_modvec = new double* [s.NRAYS];
    vis_timacu = new int* [s.NRAYS];

    for (int R = 0; R < s.NRAYS; R++) {

        eneRes = eneRay; //Inicializo energía residual

        vis_vector[R] = new vector1[ry[R].N - 1];
        vis_modvec[R] = new double[ry[R].N];
        vis_timacu[R] = new int[ry[R].N];

        ///////////////////////////////////////////

        vis_modvec[R][0] = 0.0;
        vis_timacu[R][0] = 0.0;
        printf("\n");

        for (int i = 0; i < ry[R].N - 1; i++) {
            //Guardo el vector con la ruta de la reflexion
            vis_vector[R][i] = ry[R].r[i + 1] - ry[R].r[i];
            //Registro la distancia acumulada de las reflexiones anteriores
            vis_modvec[R][i + 1] = vis_modvec[R][i] + ry[R].d[i + 1];
            vis_timacu[R][i + 1] = int((1000 * vis_modvec[R][i + 1] / V_SON));

        }

        //Captacion en recpetor de reflexiones especulare sy carga de 
        for (int i = 1; i < ry[R].N; i++) {

            int indTri, indTime;            //indices para la matriz de transicion de energia
            indTri = ry[R].idTriangle[i];
            indTime = vis_timacu[R][i];     //instancias de tiempo donde se produjo el choque


            double alfa, delta;
            alfa = 0.2;
            delta = 0.15;


            //alfa = r.p[ry[R].Plane[i]].m.alfa;
            //delta = r.p[ry[R].Plane[i]].m.delta;

            mE.energia[indTri][indTime] += (eneRes * (1 - alfa) * delta); //aquí guardo la enerfia difusa cargo la matriz

            //reception ray tracing,  caoptacion del receptor
            //punto de partida del rayo, un tiempo t, la maxima distanciay el doyble que es la energia que va 
            re.receptionRayTracing(ry[R].r[i - 1], vis_vector[R][i - 1], vis_timacu[R][i], r.maxd, eneRes);
            //estamos actuyalizando la energia residual del rayo la energia que le queda.
            eneRes = eneRes * (1 - alfa) * (1 - delta);//energia reflejada especularmente
        }
    }
}