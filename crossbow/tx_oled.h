#pragma once

#ifndef TX_OLED_H
#define TX_OLED_H

#include <Adafruit_SSD1306.h>
#include "Wire.h"
#include "variables.h"
#include "tactile.h"
#include "radio_node.h"

extern RadioNode radioNode;

enum txOledPages {
    TX_PAGE_NONE,
    TX_PAGE_INIT,
    TX_PAGE_STATS,
    TX_PAGE_PWR,
    TX_PAGE_BIND,
    TX_PAGE_MODE
};

#define TX_OLED_PAGE_COUNT 5

const uint8_t pageSequence[TX_OLED_PAGE_COUNT] = {
    TX_PAGE_INIT,
    TX_PAGE_STATS,
    TX_PAGE_PWR,
    TX_PAGE_BIND,
    TX_PAGE_MODE
};

class TxOled {
    public:
        TxOled(void);
        void init();
        void loop(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState,
            Tactile *button0,
            Tactile *button1
        );
        void page(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState,
            int page
        );
    private:
        Adafruit_SSD1306 _display;
        void renderPageInit(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState
        );
        void renderPageStats(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState
        );
        void renderPagePwr(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState
        );
        void renderPageBind(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState
        );
        void renderPageMode(
            RxDeviceState_t *rxDeviceState,
            TxDeviceState_t *txDeviceState
        );
        uint8_t _page = TX_PAGE_NONE;
        uint8_t _mainPageSequenceIndex = 0;
};

#endif