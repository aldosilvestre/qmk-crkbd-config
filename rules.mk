RGB_MATRIX_ENABLE = yes
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
TAP_DANCE_ENABLE = yes	# tap dance
NKRO_ENABLE        = yes
EXTRAKEY_ENABLE = yes

MOUSEKEY_ENABLE = no    # Mouse keys
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
AUDIO_ENABLE = no
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration

SRC += oled.c
SRC += keylogger.c
SRC += tap_dances.c
