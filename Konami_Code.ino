#include "Nintendo.h" // https://github.com/NicoHood/Nintendo

// Revisar el readme en el repo del proyecto https://github.com/pweinzettel/konami_code
// Solo es necesario conectar data, 3v3 y ground, el resto de los pines NO es necesario cablearlos

// Setear pin de datos en puerto 17, este debe ir conectado a la consola
CGamecubeConsole GamecubeConsole(17);

// Tomamos la estructura de datos y la nombramos como gcdata
Gamecube_Data_t gcdata = defaultGamecubeData;

// Es necesario declarar un mando, aunque no lo usemos?
// CGamecubeController GamecubeController1(15);

// init variables globales - pinxAxis y pinyAxis son ANALOGICOS con valores de 0 a 255, por lo que el centro es 128
int btn_A = 0;
int btn_B = 0;
int btn_X = 0;
int btn_Y = 0;
int btn_START = 0;
int btn_Z = 0;
int btn_L = 0;
int btn_R = 0;
int btn_aL = 0;
int btn_aR = 0;
int dpad_LEFT = 0;
int dpad_RIGHT = 0;
int dpad_UP = 0;
int dpad_DOWN = 0;
int apad_X = 128;
int apad_Y = 128;
int joyc_X = 128;
int joyc_Y = 128;

void setup()
{
  // esperamos a que este activo el mando
  // GamecubeController1.read();
}

void release_all() {
  // Botones DIGITAL
  btn_A = 0;
  btn_B = 0;
  btn_X = 0;
  btn_Y = 0;

  btn_START = 0;

  // Botones SUPERIORES
  btn_Z = 0;
  // botones hybridos, R L pueden usarse como analogicos o digitales
  // DIGITALES
  btn_L = 0;
  btn_R = 0;
  // ANALOGICOS
  btn_aL = 0;
  btn_aR = 0;

  // Pad DIGITAL
  dpad_LEFT = 0;
  dpad_RIGHT = 0;
  dpad_UP = 0;
  dpad_DOWN = 0;

  // Pad ANALOGICO
  apad_X = 128;
  apad_Y = 128;

  // Joystick C
  joyc_X = 128;
  joyc_Y = 128;
}

void gcsend() {
  gcdata.report.a = btn_A;
  gcdata.report.b = btn_B;
  gcdata.report.x = btn_X;
  gcdata.report.y = btn_Y;
  gcdata.report.start = btn_START;
  gcdata.report.z = btn_Z;
  gcdata.report.l = btn_L;
  gcdata.report.r = btn_R;
  gcdata.report.left = btn_aL;
  gcdata.report.right = btn_aR;
  gcdata.report.dleft = dpad_LEFT;
  gcdata.report.dright = dpad_RIGHT;
  gcdata.report.dup = dpad_UP;
  gcdata.report.ddown = dpad_DOWN;
  gcdata.report.xAxis = apad_X;
  gcdata.report.yAxis = apad_Y;
  gcdata.report.cxAxis = joyc_X;
  gcdata.report.cyAxis = joyc_Y;

  // Mandar data a la consola
  GamecubeConsole.write(gcdata);
}

void one_shoot() {
  int press_delay = 200;
  int space_delay = 200;

  gcsend();
  delay(press_delay);
  release_all();
  gcsend();
  delay(space_delay);
}

void loop()
{
  // https://en.wikipedia.org/wiki/Konami_Code
  // Arriba Arriba Abajo Abajo Izq Der Izq Der B A
  dpad_UP = 1;
  one_shoot();

  dpad_UP = 1;
  one_shoot();

  dpad_DOWN = 1;
  one_shoot();

  dpad_DOWN = 1;
  one_shoot();

  dpad_LEFT = 1;
  one_shoot();

  dpad_RIGHT = 1;
  one_shoot();

  dpad_LEFT = 1;
  one_shoot();

  dpad_RIGHT = 1;
  one_shoot();

  btn_B = 1;
  one_shoot();

  btn_A = 1;
  one_shoot();
}
