RGBLIGHT_ENABLE = yes
# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        # ./lib/keylogger.c \
        # ./lib/timelogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \

OLED_DRIVER_ENABLE = yes
