#include "app.h"
#include "factory.h"

int main(int argc, const char ** argv){
  factory_init();
  app_init();
  app_run();
  return 0;
}
