#include <toBeSorted/counters/counter.h>

static u16 getBaseCapacity();
static u16 getExtraWalletCapacity();

class RupeeCounter : public Counter {
public:
    RupeeCounter();
    /* 8016DEF0 */ ~RupeeCounter() {}
    /* 8016DF50 */ virtual u16 getMax() override {
        return (getBaseCapacity() + getExtraWalletCapacity());
    }
};

struct WalletStruct {
    u32 flag;
    u16 capacity;
};

// TODO set up item flag manager
extern "C" void *lbl_80575400;
extern "C" u16 fn_800BF5E0(void *data, u16 flag);

/* 8016DE10 */ static u16 getBaseCapacity() {
    int i = 0;
    /* 804E91B0 */ WalletStruct wallet_definitions[4] = {
            {0x6c, 500},
            {0x6d, 1000},
            {0x6e, 5000},
            {0x6f, 9000},
    };
    const WalletStruct *wallet = &wallet_definitions[3];
    for (; i < 4; i++, wallet--) {
        if (fn_800BF5E0(lbl_80575400, wallet->flag)) {
            return wallet->capacity;
        }
    }
    return 300;
}

// TODO main counters class
extern "C" u16 fn_8016D730(u16);

/* 8016DEC0 */ static u16 getExtraWalletCapacity() {
    return 300 * fn_8016D730(0x27);
}

/* 80575610 */ RupeeCounter lbl_80575610;

/* 8016DF30 */ RupeeCounter::RupeeCounter() : Counter(0x1f5) {}
