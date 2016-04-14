/*
 * BASE FOR VIDEO SYNTH
 *
 */
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/videodev.h>
#include <linux/videodev2.h>
#include <FTGL/ftgl.h>

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glx.h>
#include <GL/glxext.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Cg/cgGL.h>
#include <X11/extensions/xf86vmode.h>
#include <X11/keysym.h>
#include <pthread.h>     /* posix thread functions and data structures */
#include <string.h>
#include <math.h>
#include <avifile-0.7/avifile.h>
#include <avifile-0.7/avm_default.h>
#include <avifile-0.7/image.h>
#include <avifile-0.7/infotypes.h>
#include "3ds.h"
#include "fft.h"
#define ALSA_PCM_OLD_HW_PARAMS_API
#define ALSA_PCM_OLD_SW_PARAMS_API
#include <alsa/asoundlib.h> /*alsa audio interface headers*/

/* stuff about our window grouped together */
typedef struct {
    Display *dpy;
    int screen;
    Window win;
    GLXContext ctx;
    XSetWindowAttributes attr;
    Bool fs;
    Bool doubleBuffered;
    XF86VidModeModeInfo deskMode;
    int x, y;
    unsigned int width, height;
    unsigned int depth;    
} GLWindow;

typedef struct {
    int width;
    int height;
    unsigned char *data;
} textureImage;


/* attributes for a single buffered visual in RGBA format with at least
 * 4 bits per color and a 16 bit depth buffer */
static int attrListSgl[] = {GLX_RGBA, GLX_RED_SIZE, 4, 
    GLX_GREEN_SIZE, 4, 
    GLX_BLUE_SIZE, 4, 
    GLX_DEPTH_SIZE, 24,
    None};

/* attributes for a double buffered visual in RGBA format with at least
 * 4 bits per color and a 16 bit depth buffer */
static int attrListDbl[] = { GLX_RGBA, GLX_DOUBLEBUFFER, 
    GLX_RED_SIZE, 4, 
    GLX_GREEN_SIZE, 4, 
    GLX_BLUE_SIZE, 4, 
    GLX_DEPTH_SIZE, 24,
    None };
