#include "libft.h"

/*
** Dichotomic research
*/

int dichotomia(int *start, int *end, int **tab, int val)
{
	int mid;
	int	ok;

	ok = -1;
	if (((*end - *id) > 1))
	{
		mid = (*start + *end) / 2;
		ok = (tab[mid] == val);
    	if (tab[im] > val)
    		end = mid;
    	else
    		id = im;
	}
	return ((ok == 1) ? tab[mid] : dichotomia(start, end, tab, val));
}

/*
** Return the number of lines in the file.
*/

int nb_lines(char *av)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		i++;
		ft_strdel(&s);
	}
	close(fd);
	return (i);
}

/*
** Fill the int tab 
*/

int fill_tab(char *av, int **tab)
{
	int		i;
	int		fd;
	char	*s;

	i = -1;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		if (++i == 0)
			*val = atoi(s);
		else
		{	
			s = ft_strtrim(s);
			ft_strdel(&s);
		}
	}
	close(fd);
	return
}

/*
** Init the dichotomia's values and start it.
*/

int main (int ac, char **av)
{
	int start;
	int end;
	int *tab;
	int res;
	int val;

	if (ac != 2)
		return (-1);
	start = 0;
	val = 0;
	end = size = nb_lines(av[1]);
	fill_tab(av[1], &tab, &val);
	res = dichotomia(&start, &end, &tab);
	(res == -1) ? printf("Value not found.\n") : printf("Index of the value = %d\n", res);
	return (0);
}
































int main()
{
  /* on déclare un tableau d'entiers que l'on initialise avec 8 entiers rangés par ordre croissant */
  int tab[10] = {12, 14, 20, 25, 26, 28, 35, 99};
  int nbVal = 8;  //nombre de valeurs stockées dans le tableau "tab[]"
  
  /* on demande la valeur que l'utilisateur veut rechercher dans le tableau */
  int val;  //variable stockant la valeur à rechercher dans le tableau
  cout << "Quelle valeur voulez-vous rechercher ?" << endl;
  cin >> val;
  
  /* on appelle la fonction de recherche dichotomique et on affiche le résultat  */
  int indiceRetourne = rechercheDicho(tab, nbVal, val);

  if(indiceRetourne != -1) cout << "Votre valeur est a l'indice : " << indiceRetourne << endl;
  else cout << "Votre valeur n'est pas dans le tableau." << endl;


  return 0;
}

/* fonction de recherche dichotomique qui renvoie un indice où se trouve la valeur 
"val" s'il est dans le tableau "tab[]" et -1 si cette valeur n'y est pas */
int rechercheDicho(int tab[], int nbVal, int val){

  /* déclaration des variables locales à la fonction */
  bool trouve;  //vaut faux tant que la valeur "val" n'aura pas été trouvée
  int id;  //indice de début
  int ifin;  //indice de fin
  int im;  //indice de "milieu"
  
  /* initialisation de ces variables avant la boucle de recherche */
  trouve = false;  //la valeur n'a pas encore été trouvée
  id = 0;  //intervalle de recherche compris entre 0...
  ifin = nbVal;  //...et nbVal
  
  /* boucle de recherche */
  while(!trouve && ((ifin - id) > 1)){

    im = (id + ifin)/2;  //on détermine l'indice de milieu
    
    trouve = (tab[im] == val);  //on regarde si la valeur recherchée est à cet indice
    
    if(tab[im] > val) ifin = im;  //si la valeur qui est à la case "im" est supérieure à la valeur recherchée, l'indice de fin "ifin" << devient >> l'indice de milieu, ainsi l'intervalle de recherche est restreint lors du prochain tour de boucle
    else id = im;  //sinon l'indice de début << devient >> l'indice de milieu et l'intervalle est de la même façon restreint
  }
  
  /* test conditionnant la valeur que la fonction va renvoyer */
  if(tab[id] == val) return(id);  //si on a trouvé la bonne valeur, on retourne l'indice
  else return(-1);  //sinon on retourne -1
  
}
