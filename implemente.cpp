#include <iostream> // std::cout, std::fixed
#include <iomanip> // std::setprecision

struct aluno {
   float nota[3];
   float media;
};

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a)
{
    a->media=0;
   for(int i=0;i<3;i++){
    a->media += a->nota[i];
   }
   a->media/=3;
}

int main()
{
   aluno a;
   int i;
   for (i = 0; i < 3; i++)
      std::cin >> a.nota[i];
   
   calcula_media(&a);
   // Chame a função 'calcula_media' passando o aluno 'a' por referência.
   
   
   std::cout << std::fixed;
   std::cout << std::setprecision(1) << a.media;
   
   return 0;
}