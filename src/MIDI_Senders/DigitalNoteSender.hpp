#pragma once

#include <Control_Surface/Control_Surface_Class.hpp>

BEGIN_CS_NAMESPACE

/**
 * @brief   Class that sends MIDI note on and off messages.
 * 
 * @ingroup MIDI_Senders
 */
class DigitalNoteSender {
  public:
    DigitalNoteSender(uint8_t velocity = 0x7F) : velocity(velocity) {}
    /// Send a note on message to the given address with this object's velocity
    /// as velocity.
    void sendOn(MIDIAddress address) {
        Control_Surface.sendNoteOn(address, getVelocity());
    }
    /// Send a note off message to the given address with 0x7F as velocity.
    void sendOff(MIDIAddress address) {
        Control_Surface.sendNoteOff(address, 0x7F);
    }

    /// Send a note on message to the given address with value
    /// as velocity. for used on faders
    void send(uint8_t value, MIDIAddress address) {
        Control_Surface.sendNoteOn(address, value);
    }


    void setVelocity(uint8_t velocity) { this->velocity = velocity; }
    uint8_t getVelocity() const { return this->velocity; }

    /// Get the resolution of the sender in bits (always returns 7).
    constexpr static uint8_t precision() { return 7; }


  private:
    uint8_t velocity;
};

END_CS_NAMESPACE