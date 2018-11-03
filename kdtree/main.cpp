#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct ponto
{
	int pX, pY;
	char Tag;
};
typedef struct ponto Ponto;


struct KDNode
{
	Ponto info;
	char desc; // 0 para X e 1 para Y
	struct KDNode *esq, *dir;
	
};
typedef struct KDNode No;

void inicalizaArvore(No **arvore)
{
	*arvore = (No*)malloc(sizeof(No));
        *arvore = NULL;
}


No *criaNo(Ponto p, char disc)
{
	No *np = (No*)malloc(sizeof(No));
	np->esq = NULL;
	np->dir = NULL;
	np->desc = disc;
	np->info = p;
	
	return np;
}



int comparaPontos(Ponto pA, Ponto pB, char disc) 
{
        if (disc == 1) 
	{
            if (pA.pY == pB.pY)
                return 0;
            else 
            {
                return (pA.pY > pB.pY) ? 1 : -1;
            }

        } 
	else 
	{
            if (pA.pX == pB.pX)
                return 0;
            else 
            {
                return (pA.pX > pB.pX) ? 1 : -1;
            }
        }
}

void percorreOrdem(No *A)
{
    if (A == NULL)
        return;
    printf(" (%d, %d) ", A->info.pX, A->info.pY);
    percorreOrdem(A->esq);
    percorreOrdem(A->dir);
}

void insereKDTree(No **arvore, Ponto p)
{
	No *arAnt = NULL;
	No *arAux = NULL;
        
	if((*arvore) == NULL)
	{
		*arvore = criaNo(p, 0);
	}
	else
	{
		arAnt = *arvore;
		arAux = *arvore;
		//printf("aaaaaaaaaaa");
		while(arAux!=NULL)
		{
			//printf("a");
			if(comparaPontos(p, arAux->info, arAux->desc) == 1)
			{
				arAnt = arAux;
				arAux = arAux->dir;
			}
			else
			{
				arAnt = arAux;
				arAux = arAux->esq;
			}
		}

		//printf("aaaaaaaaaaa");
		if(comparaPontos(p, arAnt->info, arAnt->desc) == 1)
		{
			arAnt->dir = criaNo(p, !arAnt->desc);
		}
		else
		{
			arAnt->esq = criaNo(p, !arAnt->desc);
		}
	}
}

Ponto criaPonto(int x, int y, char desc)
{
    Ponto p;
    p.pX = x;
    p.pY = y;
    p.Tag = desc;
	
    return p;
}


int main()
{
	No *Arvore = NULL;
	Ponto p1, p2, p3, p4, p5, p6, p7;
        
	inicalizaArvore(&Arvore);
	p1 = criaPonto(4, 6, 'A');
	p2 = criaPonto(2, 4, 'B');
	p3 = criaPonto(6, 3, 'C');
	p4 = criaPonto(7, 2, 'D');
	p5 = criaPonto(8, 7, 'E');
	p6 = criaPonto(10, 1, 'F');
        p7 = criaPonto(15, 13, 'G');
	
	//printf("aaaaaaaaaaa");
	insereKDTree(&Arvore, p1);
	insereKDTree(&Arvore, p2);
	insereKDTree(&Arvore, p3);
	insereKDTree(&Arvore, p4);
	insereKDTree(&Arvore, p5);
	insereKDTree(&Arvore, p6);
        insereKDTree(&Arvore, p7);
	percorreOrdem(Arvore);
	
}
