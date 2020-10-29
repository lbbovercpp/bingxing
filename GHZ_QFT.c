
#include "QuEST.h"
#include "stdio.h"
#include "mytimer.hpp"
#include"omp.h"


int main (int narg, char *argv[]) {

    QuESTEnv Env = createQuESTEnv();
    double t1 = get_wall_time();

    FILE *fp=fopen("probs.dat", "w");
    if(fp==NULL){
        printf("    open probs.dat failed, Bye!");
        return 0;
    }

    FILE *fvec=fopen("stateVector.dat", "w");
    if(fp==NULL){
        printf("    open stateVector.dat failed, Bye!");
        return 0;
    }
    //初始化30个量子是这三个变量的值
    //qureg.isDensityMatrix = 0;
    //qureg.numQubitsRepresented = numQubits;
    //qureg.numQubitsInStateVec = numQubits;
    //并且全部初始化为   |0>
    //qureg.stateVec.real[0] = 1.0;
    //qureg.stateVec.imag[0] = 0.0;
    Qureg q = createQureg(30, Env);

    float q_measure[30];
    int c[30];
    for (int i = 0; i < 30; i++)
        c[i] = 0;

	/* GHZ quantum circuit */
    hadamard(q, 0);                         //0号量子为1/(2^0.5) *( |0> - |1|);
    controlledNot(q, 0, 1);                 //0 1 号电子纠缠在一起，1/(2^0.5) (|00> - |11|);
    controlledNot(q, 1, 2);                 //
    controlledNot(q, 2, 3);
    controlledNot(q, 3, 4);
    controlledNot(q, 4, 5);
    controlledNot(q, 5, 6);
    controlledNot(q, 6, 7);
    controlledNot(q, 7, 8);
    controlledNot(q, 8, 9); 
    controlledNot(q, 9, 10);
    controlledNot(q, 10, 11);
    controlledNot(q, 11, 12);
    controlledNot(q, 12, 13);
    controlledNot(q, 13, 14);
    controlledNot(q, 14, 15);
    controlledNot(q, 15, 16);
    controlledNot(q, 16, 17);
    controlledNot(q, 17, 18);
    controlledNot(q, 18, 19);
    controlledNot(q, 19, 20);
    controlledNot(q, 20, 21);
    controlledNot(q, 21, 22);
    controlledNot(q, 22, 23);
    controlledNot(q, 23, 24);
    controlledNot(q, 24, 25);
    controlledNot(q, 25, 26);
    controlledNot(q, 26, 27);
    controlledNot(q, 27, 28);
    controlledNot(q, 28, 29);
	/* end of GHZ circuit */

#pragma omp parallel num_threads(2)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				cout << "section 1 线程ID：" << omp_get_thread_num() << "\n";
			}
#pragma omp section
			{
				cout << "section 2 线程ID：" << omp_get_thread_num() << "\n";
			}
		}
    }

	/* QFT starts */
    hadamard(q, 0);
    controlledRotateZ(q, 0, 1, 1.5708);

//第一个量子
    hadamard(q, 1);

#pragma omp parallel num_threads(2)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 2, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 2, 1.5708);
			}
		}
    }    

//第二个量子

    hadamard(q, 2);

#pragma omp parallel num_threads(3)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 3, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 3, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 3, 1.5708);
			}
		}
    }      

//第三个量子
    hadamard(q, 3);
#pragma omp parallel num_threads(4)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 4, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 4, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 4, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 4, 1.5708);
			}
		}

    }     

//第四个量子
    hadamard(q, 4);

#pragma omp parallel num_threads(5)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 5, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 5, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 5, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 5, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 5, 1.5708);
			}
		}

    }


//第五个量子
    hadamard(q, 5);

#pragma omp parallel num_threads(6)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 6, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 6, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 6, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 6, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 6, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 6, 1.5708);
			}
		}

    }

//第六个量子
    hadamard(q, 6);
#pragma omp parallel num_threads(7)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 7, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 7, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 7, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 7, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 7, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 7, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 7, 1.5708);
			}
		}

    }

//第七个量子
    hadamard(q, 7);
#pragma omp parallel num_threads(8)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 8, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 8, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 8, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 8, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 8, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 8, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 8, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 8, 1.5708);
			}
		}

    }
    
    
    
//第八个量子
    hadamard(q, 8);
#pragma omp parallel num_threads(9)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 9, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 9, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 9, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 9, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 9, 0.0981748);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 5, 9, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 9, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 9, 0.785398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 8, 9, 1.5708);
			}
		}       

    }


//第九个量子   
    hadamard(q, 9);
#pragma omp parallel num_threads(10)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 10, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 10, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 10, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 10, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 10, 0.0490874);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 5, 10, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 10, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 10, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 8, 10, 0.785398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 9, 10, 1.5708);
			}
		}       

    }  
//第十个量子 
    hadamard(q, 10);
#pragma omp parallel num_threads(11)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 11, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 11, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 11, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 11, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 11, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 11, 0.0490874);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 6, 11, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 11, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 11, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 9, 11, 0.785398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 10, 11, 1.5708);
			}
		}       

    }   
    
//第十一个量子
    hadamard(q, 11);
#pragma omp parallel num_threads(12)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 12, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 12, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 12, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 12, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 12, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 12, 0.0245437);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 6, 12, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 12, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 12, 0.19635);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 9, 12, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 10, 12, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 12, 1.5708);
			}
		}       

    }  

    
//第十一个量子
    hadamard(q, 12);
#pragma omp parallel num_threads(13)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 13, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 13, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 13, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 13, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 13, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 13, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 13, 0.0245437);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 7, 13, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 13, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 13, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 13, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 13, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 13, 1.5708);
			}
		}       

    }
 
//第十三个量子
    hadamard(q, 13);
#pragma omp parallel num_threads(14)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 14, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 14, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 14, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 14, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 14, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 14, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 14, 0.0122718);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 7, 14, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 14, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 14, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 14, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 14, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 14, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 14, 1.5708);
			}
		}       

    }
 
//第十三个量子
    hadamard(q, 14);
#pragma omp parallel num_threads(15)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 15, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 15, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 15, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 15, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 15, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 15, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 15, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 15, 0.0122718);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 8, 15, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 15, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 15, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 15, 0.19635);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 12, 15, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 15, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 14, 15, 1.5708);
			}
		}       

    } 

    hadamard(q, 15);
#pragma omp parallel num_threads(16)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 16, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 16, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 16, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 16, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 16, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 16, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 16, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 16, 0.00613592);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 8, 16, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 16, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 16, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 16, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 16, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 16, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 14, 16, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 16, 1.5708);
			}
		}       

    } 

    hadamard(q, 16);
#pragma omp parallel num_threads(17)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 17, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 17, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 17, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 17, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 17, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 17, 0.00076699);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 6, 17, 0.00153398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 7, 17, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 17, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 17, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 17, 0.0245437);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 17, 0.0490874);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 12, 17, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 17, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 14, 17, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 17, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 16, 17, 1.5708);
			}
		}        

    } 
    
    
    
    
    

    hadamard(q, 17);
#pragma omp parallel num_threads(18)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 18, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 1, 18, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 18, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 18, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 18, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 18, 0.000383495);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 6, 18, 0.00076699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 7, 18, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 8, 18, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 18, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 18, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 18, 0.0245437);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 12, 18, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 18, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 14, 18, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 18, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 16, 18, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 17, 18, 1.5708);
			}
		}        

    } 

    hadamard(q, 18);
#pragma omp parallel num_threads(19)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 19, 5.99211e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 1, 19, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 19, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 19, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 19, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 19, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 19, 0.000383495);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 7, 19, 0.00076699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 8, 19, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 9, 19, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 10, 19, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 11, 19, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 19, 0.0245437);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 13, 19, 0.0490874);
			}
#pragma omp section
			{
    controlledRotateZ(q, 14, 19, 0.0981748);
			}
#pragma omp section
			{
    controlledRotateZ(q, 15, 19, 0.19635);
			}
#pragma omp section
			{
    controlledRotateZ(q, 16, 19, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 17, 19, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 18, 19, 1.5708);
			}
		}        

    }
    
    
    

    hadamard(q, 19);
#pragma omp parallel num_threads(20)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 20, 2.99606e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 1, 20, 5.99211e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 2, 20, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 20, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 20, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 20, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 20, 0.000191748);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 7, 20, 0.000383495);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 8, 20, 0.00076699);
			}
#pragma omp section
			{
		  controlledRotateZ(q, 9, 20, 0.00153398);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 10, 20, 0.00306796);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 11, 20, 0.00613592);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 12, 20, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 20, 0.0245437);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 14, 20, 0.0490874);
			}
#pragma omp section
			{
        controlledRotateZ(q, 15, 20, 0.0981748);
			}
#pragma omp section
			{
      controlledRotateZ(q, 16, 20, 0.19635);
			}
#pragma omp section
			{
       controlledRotateZ(q, 17, 20, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 18, 20, 0.785398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 19, 20, 1.5708);
			}
		}        

    } 
    
    hadamard(q, 20);
#pragma omp parallel num_threads(21)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				controlledRotateZ(q, 0, 21, 1.49803e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 1, 21, 2.99606e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 2, 21, 5.99211e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 21, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 21, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 21, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 21, 9.58738e-05);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 7, 21, 0.000191748);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 8, 21, 0.000383495);
			}
#pragma omp section
			{
		  controlledRotateZ(q, 9, 21, 0.00076699);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 10, 21, 0.00153398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 11, 21, 0.00306796);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 12, 21, 0.00613592);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 21, 0.0122718);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 14, 21, 0.0245437);
			}
#pragma omp section
			{
       controlledRotateZ(q, 15, 21, 0.0490874);
			}
#pragma omp section
			{
      controlledRotateZ(q, 16, 21, 0.0981748);
			}
#pragma omp section
			{
       controlledRotateZ(q, 17, 21, 0.19635);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 18, 21, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 19, 21, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 20, 21, 1.5708);
			}
		}        

    }  

    hadamard(q, 21);
#pragma omp parallel num_threads(22)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				 controlledRotateZ(q, 0, 22, 7.49014e-07);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 1, 22, 1.49803e-06);
			}
#pragma omp section
			{
				   controlledRotateZ(q, 2, 22, 2.99606e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 22, 5.99211e-06);
			}
#pragma omp section
			{
				   controlledRotateZ(q, 4, 22, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 22, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 22, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 22, 9.58738e-05);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		controlledRotateZ(q, 8, 22, 0.000191748);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 9, 22, 0.000383495);
			}
#pragma omp section
			{
		   controlledRotateZ(q, 10, 22, 0.00076699);
			}
#pragma omp section
			{
			     controlledRotateZ(q, 11, 22, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 22, 0.00306796);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 13, 22, 0.00613592);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 14, 22, 0.0122718);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 15, 22, 0.0245437);
			}
#pragma omp section
			{
       controlledRotateZ(q, 16, 22, 0.0490874);
			}
#pragma omp section
			{
      controlledRotateZ(q, 17, 22, 0.0981748);
			}
#pragma omp section
			{
       controlledRotateZ(q, 18, 22, 0.19635);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 19, 22, 0.392699);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 20, 22, 0.785398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 22, 1.5708);
			}
		}        

    }   

    hadamard(q, 22);
#pragma omp parallel num_threads(23)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
				   controlledRotateZ(q, 0, 23, 3.74507e-07);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 1, 23, 7.49014e-07);
			}
#pragma omp section
			{
				   controlledRotateZ(q, 2, 23, 1.49803e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 23, 2.99606e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 4, 23, 5.99211e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 23, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 23, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 23, 4.79369e-05);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		 controlledRotateZ(q, 8, 23, 9.58738e-05);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 9, 23, 0.000191748);
			}
#pragma omp section
			{
		  controlledRotateZ(q, 10, 23, 0.000383495);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 11, 23, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 23, 0.00153398);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 13, 23, 0.00306796);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 14, 23, 0.00613592);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 15, 23, 0.0122718);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 16, 23, 0.0245437);
			}
#pragma omp section
			{
       controlledRotateZ(q, 17, 23, 0.0490874);
			}
#pragma omp section
			{
       controlledRotateZ(q, 18, 23, 0.0981748);
			}
#pragma omp section
			{
        controlledRotateZ(q, 19, 23, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 20, 23, 0.392699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 23, 0.785398);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 23, 1.5708);
			}
		}        

    }   

    hadamard(q, 23);
#pragma omp parallel num_threads(24)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 0, 24, 1.87254e-07);
			}
#pragma omp section
			{
			controlledRotateZ(q, 1, 24, 3.74507e-07);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 2, 24, 7.49014e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 24, 1.49803e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 24, 2.99606e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 24, 5.99211e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 24, 1.19842e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 24, 2.39684e-05);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		 controlledRotateZ(q, 8, 24, 4.79369e-05);
			}
#pragma omp section
			{
			controlledRotateZ(q, 9, 24, 9.58738e-05);
			}
#pragma omp section
			{
		  controlledRotateZ(q, 10, 24, 0.000191748);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 11, 24, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 24, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 24, 0.00153398);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 14, 24, 0.00306796);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 24, 0.00613592);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 16, 24, 0.0122718);
			}
#pragma omp section
			{
       controlledRotateZ(q, 17, 24, 0.0245437);
			}
#pragma omp section
			{
      controlledRotateZ(q, 18, 24, 0.0490874);
			}
#pragma omp section
			{
        controlledRotateZ(q, 19, 24, 0.0981748);
			}
#pragma omp section
			{
			controlledRotateZ(q, 20, 24, 0.19635);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 24, 0.392699);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 24, 0.785398);
			}
#pragma omp section
			{
			controlledRotateZ(q, 23, 24, 1.5708);
			}
		}        

    }   

    hadamard(q, 24);
#pragma omp parallel num_threads(25)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 0, 25, 9.36268e-08);
			}
#pragma omp section
			{
			controlledRotateZ(q, 1, 25, 1.87254e-07);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 2, 25, 3.74507e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 25, 7.49014e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 4, 25, 1.49803e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 25, 2.99606e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 25, 5.99211e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 25, 1.19842e-05);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		 controlledRotateZ(q, 8, 25, 2.39684e-05);
			}
#pragma omp section
			{
			controlledRotateZ(q, 9, 25, 4.79369e-05);
			}
#pragma omp section
			{
		  controlledRotateZ(q, 10, 25, 9.58738e-05);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 11, 25, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 25, 0.000383495);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 25, 0.00076699);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 14, 25, 0.00153398);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 25, 0.00306796);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 16, 25, 0.00613592);
			}
#pragma omp section
			{
        controlledRotateZ(q, 17, 25, 0.0122718);
			}
#pragma omp section
			{
      controlledRotateZ(q, 18, 25, 0.0245437);
			}
#pragma omp section
			{
         controlledRotateZ(q, 19, 25, 0.0490874);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 20, 25, 0.0981748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 25, 0.19635);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 25, 0.392699);
			}
#pragma omp section
			{
			controlledRotateZ(q, 23, 25, 0.785398);
			}
		}   
        #pragma omp sections //第4个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 24, 25, 1.5708);
			}
		}           

    }   

    hadamard(q, 25);
#pragma omp parallel num_threads(26)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 0, 26, 4.68134e-08);
			}
#pragma omp section
			{
			controlledRotateZ(q, 1, 26, 9.36268e-08);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 2, 26, 1.87254e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 26, 3.74507e-07);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 4, 26, 7.49014e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 26, 1.49803e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 6, 26, 2.99606e-06);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 7, 26, 5.99211e-06);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		  controlledRotateZ(q, 8, 26, 1.19842e-05);
			}
#pragma omp section
			{
			controlledRotateZ(q, 9, 26, 2.39684e-05);
			}
#pragma omp section
			{
		controlledRotateZ(q, 10, 26, 4.79369e-05);
			}
#pragma omp section
			{
			    controlledRotateZ(q, 11, 26, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 26, 0.000191748);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 13, 26, 0.000383495);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 14, 26, 0.00076699);
			}
#pragma omp section
			{
				controlledRotateZ(q, 15, 26, 0.00153398);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 16, 26, 0.00306796);
			}
#pragma omp section
			{
        controlledRotateZ(q, 17, 26, 0.00613592);
			}
#pragma omp section
			{
     controlledRotateZ(q, 18, 26, 0.0122718);
			}
#pragma omp section
			{
          controlledRotateZ(q, 19, 26, 0.0245437);
			}
#pragma omp section
			{
			controlledRotateZ(q, 20, 26, 0.0490874);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 26, 0.0981748);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 26, 0.19635);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 23, 26, 0.392699);
			}
		}   
        #pragma omp sections //第4个sections
		{
#pragma omp section
			{
			controlledRotateZ(q, 24, 26, 0.785398);
			}
#pragma omp section
			{
			controlledRotateZ(q, 25, 26, 1.5708);
			}
		}           

    }

    hadamard(q, 26);
#pragma omp parallel num_threads(27)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 0, 27, 2.34067e-08);
			}
#pragma omp section
			{
			controlledRotateZ(q, 1, 27, 4.68134e-08);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 27, 9.36268e-08);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 27, 1.87254e-07);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 4, 27, 3.74507e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 5, 27, 7.49014e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 27, 1.49803e-06);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 27, 2.99606e-06);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		  controlledRotateZ(q, 8, 27, 5.99211e-06);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 9, 27, 1.19842e-05);
			}
#pragma omp section
			{
		controlledRotateZ(q, 10, 27, 2.39684e-05);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 11, 27, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 27, 9.58738e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 27, 0.000191748);
			}
#pragma omp section
			{
				controlledRotateZ(q, 14, 27, 0.000383495);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 15, 27, 0.00076699);
			}
		} 
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			  controlledRotateZ(q, 16, 27, 0.00153398);
			}
#pragma omp section
			{
        controlledRotateZ(q, 17, 27, 0.00306796);
			}
#pragma omp section
			{
      controlledRotateZ(q, 18, 27, 0.00613592);
			}
#pragma omp section
			{
          controlledRotateZ(q, 19, 27, 0.0122718);
			}
#pragma omp section
			{
			controlledRotateZ(q, 20, 27, 0.0245437);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 21, 27, 0.0490874);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 27, 0.0981748);
			}
#pragma omp section
			{
			  controlledRotateZ(q, 23, 27, 0.19635);
			}
		}   
        #pragma omp sections //第4个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 24, 27, 0.392699);
			}
#pragma omp section
			{
			controlledRotateZ(q, 25, 27, 0.785398);
			}
#pragma omp section
			{
			controlledRotateZ(q, 26, 27, 1.5708);
			}
		}           

    }    


    hadamard(q, 27);
#pragma omp parallel num_threads(28)
	{
#pragma omp sections //第1个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 0, 28, 1.17033e-08);
			}
#pragma omp section
			{
			controlledRotateZ(q, 1, 28, 2.34067e-08);
			}
#pragma omp section
			{
				controlledRotateZ(q, 2, 28, 4.68134e-08);
			}
#pragma omp section
			{
				controlledRotateZ(q, 3, 28, 9.36268e-08);
			}
#pragma omp section
			{
				  controlledRotateZ(q, 4, 28, 1.87254e-07);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 5, 28, 3.74507e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 6, 28, 7.49014e-07);
			}
#pragma omp section
			{
				controlledRotateZ(q, 7, 28, 1.49803e-06);
			}
		}
        #pragma omp sections //第2个sections
		{
#pragma omp section
			{
		  controlledRotateZ(q, 8, 28, 2.99606e-06);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 9, 28, 5.99211e-06);
			}
#pragma omp section
			{
		 controlledRotateZ(q, 10, 28, 1.19842e-05);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 11, 28, 2.39684e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 12, 28, 4.79369e-05);
			}
#pragma omp section
			{
				controlledRotateZ(q, 13, 28, 9.58738e-05);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 14, 28, 0.000191748);
			}
#pragma omp section
			{
				 controlledRotateZ(q, 15, 28, 0.000383495);
			}
		}    
        #pragma omp sections //第3个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 16, 28, 0.00076699);
			}
#pragma omp section
			{
        controlledRotateZ(q, 17, 28, 0.00153398);
			}
#pragma omp section
			{
      controlledRotateZ(q, 18, 28, 0.00306796);
			}
#pragma omp section
			{
         controlledRotateZ(q, 19, 28, 0.00613592);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 20, 28, 0.0122718);
			}
#pragma omp section
			{
				controlledRotateZ(q, 21, 28, 0.0245437);
			}
#pragma omp section
			{
			controlledRotateZ(q, 22, 28, 0.0490874);
			}
#pragma omp section
			{
			   controlledRotateZ(q, 23, 28, 0.0981748);
			}
		}   
        #pragma omp sections //第4个sections
		{
#pragma omp section
			{
			 controlledRotateZ(q, 24, 28, 0.19635);
			}
#pragma omp section
			{
			controlledRotateZ(q, 25, 28, 0.392699);
			}
#pragma omp section
			{
			controlledRotateZ(q, 26, 28, 0.785398);
			}
#pragma omp section
			{
			 controlledRotateZ(q, 27, 28, 1.5708);
			}
		}           

    }
   
    hadamard(q, 28);
	/* end of QFT circuit */

    printf("\n");
    for(long long int i=0; i<30; ++i){
        q_measure[i] = calcProbOfOutcome(q,  i, 1);
        //printf("  probability for q[%2lld]==1 : %lf    \n", i, q_measure[i]);
        fprintf(fp, "Probability for q[%2lld]==1 : %lf    \n", i, q_measure[i]);
    }
    fprintf(fp, "\n");
    printf("\n");

    for(int i=0; i<10; ++i){
        Complex amp = getAmp(q, i);
        //printf("Amplitude of %dth state vector: %f\n", i, prob);
	fprintf(fvec, "Amplitude of %dth state vector: %12.6f,%12.6f\n", i, amp.real, amp.imag);
    }

    double t2 = get_wall_time();
    printf("Complete the simulation takes time %12.6f seconds.", t2 - t1);
    printf("\n");
    destroyQureg(q, Env);
    destroyQuESTEnv(Env);

    return 0;
}
