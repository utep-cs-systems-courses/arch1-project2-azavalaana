#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void buzzer_change_period3(){
  //change period for SW3
  if (switch3_state_changed) {
    switch3_state_down ? buzzer_set_period(5000) : buzzer_set_period(0);
  }
  switch3_state_changed = 0;
  /*
  if (switch2_state_changed) {
    switch2_state_down ? buzzer_set_period(1000) : buzzer_set_period(0);
  }
  switch2_state_changed = 0;
  */
}

void buzzer_change_period2(){
  //change period for SW2
  if (switch2_state_changed) {
    switch2_state_down ? buzzer_set_period(2000) : buzzer_set_period(0);
  }
  switch2_state_changed = 0;
}

void buzzer_change_period4(){
  if (switch4_state_changed) {
    switch4_state_down ? buzzer_set_period(8000) : buzzer_set_period(0);
  }
  switch4_state_changed = 0;
}
