/* Could you modify function get_planet so that it would still have a type planet_t
result and also indicate input success or failure to the calling function? */
#include <stdio.h>
#define STRSIZ 10
typedef struct
{
  char name[STRSIZ];  /* name for planet, of maximum STDSIZ-1 characters */
  double diameter;    /*equatorial diameter in km */
  int moons;          /*number of moons */
  double orbit_time,  /*years to orbit sun once */
        rotation_time; /*hours to complete one revolution on axis */
} planet_t;

/* Gets components of and returns a planet_t structure */
planet_t fget_planet(FILE * inpfstream)  // a file implementation similar to what book has as get_planet()
{
  planet_t pl;
  fscanf(inpfstream, "%s%lf%d%lf%lf", pl.name, &pl.diameter, &pl.moons, &pl.orbit_time, &pl.rotation_time);
  return pl;
}
planet_t get_planet(int * pstatus)  // this is a possible implementation of what the exercise asks.
{
  planet_t pl;
  *pstatus = scanf("%s%lf%d%lf%lf", pl.name, &pl.diameter, &pl.moons, &pl.orbit_time, &pl.rotation_time);
  return pl;
}

/* Displays with labels all components of a planet_t structure */
void print_planet(planet_t pl) /* input - one planet structure */
{
  printf("%s\n", pl.name);
  printf(" Equatorial diameter: %.0f km\n", pl.diameter);
  printf(" Number of moons: %d\n", pl.moons);
  printf(" Time to complete one orbit of the sun: %.2f years\n", pl.orbit_time);
  printf(" Time to complete one rotation on axis: %.4f hours\n", pl.rotation_time);
}

int main()
{
  planet_t earth , newpl;
  int status=0;
  FILE * inpfile;
  inpfile= fopen("planets.txt", "r");
  earth = fget_planet(inpfile);
  print_planet(earth);
  fclose(inpfile);
  // planet_t mars; mars = {"Mars", 10000, 4, 0.8, 16}; // this gives compile error....
  planet_t mars = {"Mars", 10000, 4, 0.8, 16};    // This is the acceptable way, initialize in a single step.
  print_planet(mars);
  printf("Now it is your turn to give a planet. Enter its data in a line like so :\n");
  printf("PlanetName DD.dd MM YY.yy HH.hh \n");
  printf(" where DDDD.dd is a double for the diameter of planet in km, MM is an integer of how many moons it has\n");
  printf(" YY.yy is a double of how many (earth)years it takes the planet for a around-Sun cycle\n");
  printf(" HH.hh is a double of ho many hours it takes for a self-rotation (planets day): ");
  newpl = get_planet(&status);
  printf( "%d \n", status);
  if (status ==5) print_planet(newpl); // all 5 components were read successfuly
  else printf("There was some error in data reading\n");
  return 0;
}

// gcc -Wall -o 10.3exercise.self-check1 10.3exercise.self-check1.c

