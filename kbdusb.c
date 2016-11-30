#include <stdio.h>
#include <asm-generic/errno-base.h>
#include <string.h>
#include <linux/uinput.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>



#define DEBUG 0
/* #define CHECK_BIT(var,pos) ((var) & (1<<(pos))) */
#define TEST_BIT(var,bitval) ((var & bitval) == bitval)
/*int mapshiftkey(unsigned char keypressed) {
     2 = shift
     * 1 = ctrl
     * 4 = alt
     * 8 = super 
     * first = right
     * second = left
     */
      /*              case 0x: keysent = KEY_LEFTSHIFT;    break;
                    case 0x: keysent = KEY_RIGHTSHIFT;    break;
                    case 0x: keysent = KEY_LEFTALT;    break;
                    case 0x: keysent = KEY_RIGHTALT;    break;
                    case 0x: keysent = KEY_RIGHTCTRL;    break; 
}*/
int mapkey(unsigned char keypressed) {
                if (DEBUG) printf("mapkey keypressed=%i, ",keypressed);
                int keysent = 0;    
                switch (keypressed) {
                    case 0x04: keysent = KEY_A;    break;
                    case 0x05: keysent = KEY_B;    break;
                    case 0x06: keysent = KEY_C;    break;
                    case 0x07: keysent = KEY_D;    break;
                    case 0x08: keysent = KEY_E;    break;
                    case 0x09: keysent = KEY_F;    break;
                    case 0x0a: keysent = KEY_G;    break;
                    case 0x0b: keysent = KEY_H;    break;
                    case 0x0c: keysent = KEY_I;    break;
                    case 0x0d: keysent = KEY_J;    break;
                    case 0x0e: keysent = KEY_K;    break;
                    case 0x0f: keysent = KEY_L;    break;
                    case 0x10: keysent = KEY_M;    break;
                    case 0x11: keysent = KEY_N;    break;
                    case 0x12: keysent = KEY_O;    break;
                    case 0x13: keysent = KEY_P;    break;
                    case 0x14: keysent = KEY_Q;    break;
                    case 0x15: keysent = KEY_R;    break;
                    case 0x16: keysent = KEY_S;    break;
                    case 0x17: keysent = KEY_T;    break;
                    case 0x18: keysent = KEY_U;    break;
                    case 0x19: keysent = KEY_V;    break;
                    case 0x1a: keysent = KEY_W;    break;
                    case 0x1b: keysent = KEY_X;    break;
                    case 0x1c: keysent = KEY_Y;    break;
                    case 0x1d: keysent = KEY_Z;    break;
                    case 0x1e: keysent = KEY_1;    break;
                    case 0x1f: keysent = KEY_2;    break;
                    case 0x20: keysent = KEY_3;    break;
                    case 0x21: keysent = KEY_4;    break;
                    case 0x22: keysent = KEY_5;    break;
                    case 0x23: keysent = KEY_6;    break;
                    case 0x24: keysent = KEY_7;    break;
                    case 0x25: keysent = KEY_8;    break;
                    case 0x26: keysent = KEY_9;    break;
                    case 0x27: keysent = KEY_0;    break;
                    case 0x29: keysent = KEY_ESC;    break;
                    case 0x2d: keysent = KEY_MINUS;    break;
                    case 0x2e: keysent = KEY_EQUAL;    break;
                    case 0x2a: keysent = KEY_BACKSPACE;    break;
                    case 0x2b: keysent = KEY_TAB;    break;
                    case 0x2f: keysent = KEY_LEFTBRACE;    break;
                    case 0x30: keysent = KEY_RIGHTBRACE;    break;
                    case 0x28: keysent = KEY_ENTER;    break;
                    case 0x33: keysent = KEY_SEMICOLON;    break;
                    case 0x34: keysent = KEY_APOSTROPHE;    break;
                    case 0x35: keysent = KEY_GRAVE;    break;
                    case 0x32: keysent = KEY_BACKSLASH;    break;
                    case 0x36: keysent = KEY_COMMA;    break;
                    case 0x37: keysent = KEY_DOT;    break;
                    case 0x38: keysent = KEY_SLASH;    break;
                    case 0x55: keysent = KEY_KPASTERISK;    break;
                    case 0x2c: keysent = KEY_SPACE;    break;
                    case 0x39: keysent = KEY_CAPSLOCK; break;
                    case 0x3a: keysent = KEY_F1;    break;
                    case 0x3b: keysent = KEY_F2;    break;
                    case 0x3c: keysent = KEY_F3;    break;
                    case 0x3d: keysent = KEY_F4;    break;
                    case 0x3e: keysent = KEY_F5;    break;
                    case 0x3f: keysent = KEY_F6;    break;
                    case 0x40: keysent = KEY_F7;    break;
                    case 0x41: keysent = KEY_F8;    break;
                    case 0x42: keysent = KEY_F9;    break;
                    case 0x43: keysent = KEY_F10;    break;
                    case 0x44: keysent = KEY_F11;    break;
                    case 0x45: keysent = KEY_F12;    break;
                    case 0x53: keysent = KEY_NUMLOCK;    break;
                    case 0x47: keysent = KEY_SCROLLLOCK;    break;
                    case 0x5f: keysent = KEY_KP7;    break;
                    case 0x60: keysent = KEY_KP8;    break;
                    case 0x61: keysent = KEY_KP9;    break;
                    case 0x56: keysent = KEY_KPMINUS;    break;
                    case 0x5c: keysent = KEY_KP4;    break;
                    case 0x5d: keysent = KEY_KP5;    break;
                    case 0x5e: keysent = KEY_KP6;    break;
                    case 0x57: keysent = KEY_KPPLUS;    break;
                    case 0x59: keysent = KEY_KP1;    break;
                    case 0x5a: keysent = KEY_KP2;    break;
                    case 0x5b: keysent = KEY_KP3;    break;
                    case 0x62: keysent = KEY_KP0;    break;
                    case 0x63: keysent = KEY_KPDOT;    break;
                    case 0x58: keysent = KEY_KPENTER;    break;
                    case 0x54: keysent = KEY_KPSLASH;    break;
                    case 0x46: keysent = KEY_SYSRQ;    break;
                    case 0x4a: keysent = KEY_HOME;    break;
                    case 0x52: keysent = KEY_UP;    break;
                    case 0x4b: keysent = KEY_PAGEUP;    break;
                    case 0x50: keysent = KEY_LEFT;    break;
                    case 0x4f: keysent = KEY_RIGHT;    break;
                    case 0x4d: keysent = KEY_END;    break;
                    case 0x51: keysent = KEY_DOWN;    break;
                    case 0x4e: keysent = KEY_PAGEDOWN;    break;
                    case 0x49: keysent = KEY_INSERT;    break;
                    case 0x4c: keysent = KEY_DELETE;    break;
                    case 0x48: keysent = KEY_PAUSE;    break;
                    case 0x64: keysent = KEY_102ND; break;
                    default:
                        keysent = 0;
                }
                if (DEBUG) printf("mapkey keysent=%i\n",keysent);
                return keysent;

}

int main() {
    
    int ret;
    unsigned char buffer[80];
    unsigned char keypressed[8];
    unsigned char keypressed_prec[8];

    int r; 
    ssize_t cnt;

    /* usb_reset(lenovo_combo); */
    struct input_event ev;
    int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK | O_DSYNC);
    ret = ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ret = ioctl(fd, UI_SET_EVBIT, EV_SYN);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_A); /* Auth KEY_A */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_B); /* Auth KEY_B */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_C); /* Auth KEY_C */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_D); /* Auth KEY_D */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_E); /* Auth KEY_E */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F); /* Auth KEY_F */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_G); /* Auth KEY_G */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_H); /* Auth KEY_H */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_I); /* Auth KEY_I */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_J); /* Auth KEY_J */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_K); /* Auth KEY_K */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_L); /* Auth KEY_L */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_M); /* Auth KEY_M */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_N); /* Auth KEY_N */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_O); /* Auth KEY_O */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_P); /* Auth KEY_P */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_Q); /* Auth KEY_Q */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_R); /* Auth KEY_R */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_S); /* Auth KEY_S */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_T); /* Auth KEY_T */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_U); /* Auth KEY_U */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_V); /* Auth KEY_V */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_W); /* Auth KEY_W */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_X); /* Auth KEY_X */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_Y); /* Auth KEY_Y */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_Z); /* Auth KEY_Z */
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_0); 
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_1);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_2);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_3);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_4);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_5);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_6);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_7);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_8);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_9);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_ESC);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_MINUS);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_EQUAL);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_BACKSPACE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_TAB);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_LEFTBRACE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_RIGHTBRACE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_ENTER);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_SEMICOLON);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_APOSTROPHE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_GRAVE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_LEFTSHIFT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_BACKSLASH);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_COMMA);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_DOT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_SLASH);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_RIGHTSHIFT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPASTERISK);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_LEFTALT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_SPACE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_CAPSLOCK);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F1);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F2);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F3);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F4);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F5);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F6);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F7);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F8);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F9);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F10);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F11);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_F12);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_NUMLOCK);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_SCROLLLOCK);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP7);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP8);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP9);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPMINUS);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP4);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP5);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP6);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPPLUS);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP1);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP2);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP3);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KP0);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPDOT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPENTER);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_RIGHTCTRL);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_LEFTCTRL);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_KPSLASH);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_SYSRQ);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_RIGHTALT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_HOME);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_UP);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_PAGEUP);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_LEFT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_RIGHT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_END);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_DOWN);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_PAGEDOWN);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_INSERT);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_DELETE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_MUTE);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_VOLUMEDOWN);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_VOLUMEUP);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_CALC);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_COPY);
    ret = ioctl(fd, UI_SET_KEYBIT, KEY_102ND);
    
    struct uinput_user_dev uidev;
    memset(&uidev, 0, sizeof(uidev));
    snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "uinput-sample");
    uidev.id.bustype = BUS_USB;
    uidev.id.vendor  = 0x1234;
    uidev.id.product = 0xfedc;
    uidev.id.version = 1;
    ret = write(fd, &uidev, sizeof(uidev));
    ret = ioctl(fd, UI_DEV_CREATE);
    if (DEBUG) printf("uinput all set\n");

    memset(&buffer, 0, 80);
    FILE *in;
    in = fopen("/dev/stdin","r");
    if (DEBUG) printf("stdin is open\n");
    
    int bytes_read;
    while(fgets(buffer,79,in)) {
        /* printf("Read %i bytes\n",bytes_read); */
        if (DEBUG) printf("read: %s",buffer);
        char bytes_reported[2];
        strncpy(bytes_reported,buffer,1);
        bytes_reported[2] = 0;
        int ibytes_reported = atoi(bytes_reported);

        if (DEBUG) printf("Num bytes reported: %i\n", ibytes_reported);

        if (ibytes_reported == 9) { /* a regular key, 8 bytes + 0x71 */
            /* start at 2 to skip length and = */
        	for(int i = 2; i < ibytes_reported*2; i += 2) {
                char c1[2],c2[2];
                c1[0]=buffer[i];c2[0]=buffer[i+1];
                c1[1]=0;c2[1]=0;
                keypressed[i/2-1] = (unsigned char) strtol(c1,NULL,16)*16 + strtol(c2,NULL,16);
                if (DEBUG) printf("keypressed[%i]: %i\n",i/2-1,keypressed[i/2-1]);
            }

            /* what changed? */
            
            /* special keys */
            if (DEBUG) printf("keypressed_prec[0]=%i  keypressed[0]=%i\n",keypressed_prec[0],keypressed[0]);
            if (DEBUG) printf("bit 5 is set in keypressed[0] = %i\n",TEST_BIT(keypressed[0],32));
            
            if (keypressed_prec[0] != keypressed[0]) {
                /* released */
                if (TEST_BIT(keypressed_prec[0],1) && ! TEST_BIT(keypressed[0],1)) {
                    /* left ctrl key is released */
                    if (DEBUG) printf("left ctrl is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_LEFTCTRL;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],16) && ! TEST_BIT(keypressed[0],16)) {
                    /* right ctrl key is released */
                    if (DEBUG) printf("right ctrl is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_RIGHTCTRL;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],2) && ! TEST_BIT(keypressed[0],2)) {
                    /* left shift key is released */
                    if (DEBUG) printf("left shift is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_LEFTSHIFT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],32) && ! TEST_BIT(keypressed[0],32)) {
                    /* right shift key is released */
                    if (DEBUG) printf("right shift is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_RIGHTSHIFT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],4) && ! TEST_BIT(keypressed[0],4)) {
                    /* left alt key is released */
                    if (DEBUG) printf("left alt is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_LEFTALT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],64) && ! TEST_BIT(keypressed[0],64)) {
                    /* right alt key is released */
                    if (DEBUG) printf("right alt is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_RIGHTALT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if (TEST_BIT(keypressed_prec[0],8) && ! TEST_BIT(keypressed[0],8)) {
                    /* left alt key is released */
                    if (DEBUG) printf("win is released\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 0;
                    ev.code = KEY_COPY;
                    ret = write(fd, &ev, sizeof(ev));
                }


                /* pressed */
                if ( ! TEST_BIT(keypressed_prec[0],1) && TEST_BIT(keypressed[0],1) ) {
                    /* left ctrl key is pressed */
                    if (DEBUG) printf("left ctrl is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_LEFTCTRL;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],16) && TEST_BIT(keypressed[0],16) ) {
                    /* right ctrl key is pressed */
                    if (DEBUG) printf("right ctrl is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_RIGHTCTRL;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],2) && TEST_BIT(keypressed[0],2) ) {
                    /* left shift key is pressed */
                    if (DEBUG) printf("left shift is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_LEFTSHIFT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],32) && TEST_BIT(keypressed[0],32) ) {
                    /* right shift key is pressed */
                    if (DEBUG) printf("right shift is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_RIGHTSHIFT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],4) && TEST_BIT(keypressed[0],4) ) {
                    /* left alt key is pressed */
                    if (DEBUG) printf("left alt is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_LEFTALT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],64) && TEST_BIT(keypressed[0],64) ) {
                    /* right alt key is pressed */
                    if (DEBUG) printf("right alt is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_RIGHTALT;
                    ret = write(fd, &ev, sizeof(ev));
                }
                if ( ! TEST_BIT(keypressed_prec[0],8) && TEST_BIT(keypressed[0],8) ) {
                    /* win key is pressed */
                    if (DEBUG) printf("win is pressed\n");
                    memset(&ev, 0, sizeof(ev));
                    ev.type = EV_KEY;
                    ev.value = 1;
                    ev.code = KEY_COPY;
                    ret = write(fd, &ev, sizeof(ev));
                }
            }


            int i,j;
            for(i = 2; i < 8;i++) {
                if (keypressed_prec[i] != 0) {
                    /* still pressed? */
                    for(j = 2;j < 8;j++) {
                        if (keypressed_prec[i] == keypressed[j]) break;
                    }
                    if (j == 8) {
                        /* key is released */
                        memset(&ev, 0, sizeof(ev));
                        ev.type = EV_KEY;
                        ev.value = 0;
                        ev.code = mapkey(keypressed_prec[i]);
                        ret = write(fd, &ev, sizeof(ev));
                    }  
                }
                if (keypressed[i] != 0) {
                    /* wasn't pressed? */
                    for(j = 2;j < 8;j++) {
                        if (keypressed_prec[j] == keypressed[i]) break;
                    }
                    if (j == 8) {
                        /* key is newly pressed */
                        memset(&ev, 0, sizeof(ev));
                        ev.type = EV_KEY;
                        ev.value = 1;
                        ev.code = mapkey(keypressed[i]);
                        ret = write(fd, &ev, sizeof(ev));
                    }     
                }
            } 

            memset(&ev, 0, sizeof(ev));
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 1;
            ret = write(fd, &ev, sizeof(ev));
            
            memcpy(keypressed_prec,keypressed,8);
            if (DEBUG) printf("\n");
        }
    }
    
    return 0;
}

