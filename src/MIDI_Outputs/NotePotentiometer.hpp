#pragma once

#include <MIDI_Outputs/Abstract/MIDIFilteredAnalog.hpp>
#include <MIDI_Senders/DigitalNoteSender.hpp>

BEGIN_CS_NAMESPACE

/**
 * @brief   A class of MIDIOutputElement%s that read the analog input from a
 *          **potentiometer or fader**, and send out 7-bit MIDI 
 *          **Note On** events, with velocity setting by fader value
 * 
 * The analog input is filtered and hysteresis is applied for maximum
 * stability.  
 * This version cannot be banked.
 *
 * @ingroup MIDIOutputElements
 */
class NotePotentiometer : public MIDIFilteredAnalog<DigitalNoteSender> {
  public:
    /** 
     * @brief   Create a new NotePotentiometer object with the given analog pin, 
     *          controller number and channel.
     * 
     * @param   analogPin
     *          The analog input pin to read from.
     * @param   address
     *          The MIDI address containing the controller number [0, 119], 
     *          channel [CHANNEL_1, CHANNEL_16], and optional cable number 
     *          [CABLE_1, CABLE_16].
     */
    NotePotentiometer(pin_t analogPin, MIDIAddress address)
        : MIDIFilteredAnalog(analogPin, address, {}) {}
};

END_CS_NAMESPACE