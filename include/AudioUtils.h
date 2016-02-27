/*
 ** Copyright 2013 Intel Corporation
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **      http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 */
#pragma once

#include "SampleSpec.h"
#include <tinyalsa/asoundlib.h>
#include <stdint.h>
#include <sys/types.h>


namespace android_audio_legacy {

class AudioUtils
{
public:
    /**
     * Align on the nearest lower multiple of 16.
     * This function intends to align a value on the nearest lower value of 16 as AudioFlinger
     * expects a buffer to be a multiple of 16 in terms of frames.
     *
     * @param[in] integer that may represent a number of frames.
     *
     * @return nearest lower multiple of 16.
     */
    static uint32_t alignOn16(uint32_t u);

    /**
     * Converts a number of bytes from one sample specification to another.
     * It translates a number of bytes in the source sample specification to a number of bytes
     * in the destination sample specification corresponding to the same period of time represented
     * by the source bytes.
     * This function asserts if overflow is detected.
     *
     * @param[in] bytes in the source sample specification.
     * @param[in] ssSrc source sample specifications.
     * @param[in] ssDst destination sample specifications.
     *
     * @return number of bytes in the destination sample specification.
     */
    static size_t convertSrcToDstInBytes(size_t bytes,
                                          const SampleSpec &ssSrc,
                                          const SampleSpec &ssDst);

    /**
     * Converts a number of frames from one sample specification to another.
     * It translates a number of frames in the source sample specification to a number of frames
     * in the destination sample specification corresponding to the same period of time represented
     * by the source frames.
     * This function asserts if overflow is detected.
     *
     * @param[in] frames in the source sample specification.
     * @param[in] ssSrc source sample specifications.
     * @param[in] ssDst destination sample specifications.
     *
     * @return number of frames in the destination sample specification.
     */
    static size_t convertSrcToDstInFrames(size_t frames,
                                           const SampleSpec &ssSrc,
                                           const SampleSpec &ssDst);

    /**
     * Converts a format from Tiny alsa to HAL domains.
     *
     * @param[in] format in Tiny alsa domain.
     *
     * @return format in HAL domain, note that AUDIO_FORMAT_PCM_8_24_BIT of tiny alsa is mapped on
     *              PCM_FORMAT_S32_LE of Audio HAL.
     *              It returns AUDIO_FORMAT_INVALID in case of unsupported Tiny format.
     */
    static audio_format_t convertTinyToHalFormat(pcm_format format);

    /**
     * Converts a format from HAL to Tiny alsa domains.
     *
     * @param[in] format in HAL domain.
     *
     * @return format in HAL domain, note that AUDIO_FORMAT_PCM_8_24_BIT of AudioHAL is mapped on
     *              PCM_FORMAT_S32_LE of Tiny alsa. It returns PCM_FORMAT_S16_LE format in case of
     *              unrecognized tiny alsa format.
     */
    static pcm_format convertHalToTinyFormat(audio_format_t format);

    /**
     * Converts a card name into its index.
     * Tiny ALSA does not provide any utility to translate a name into a card index.
     * This function gets information from procfs to translate a card name into the corresponding
     * index
     *
     * @param[in] name of the sound card.
     *
     * @return index if found, negative value otherwise.
     */
    static int getCardIndexByName(const char *name);

    /**
     * Converts a time in micro to milliseconds.
     * It converts a period of time in microsecond to millisecond rounding up to the nearest milli
     * second.
     *
     * @param[in] name of the sound card.
     *
     * @return converted value in milliseconds.
     */
    static uint32_t convertUsecToMsec(uint32_t timeUsec);

    /**
     * Checks the device is an input device.
     * This function works with AudioSystem REV1.0 API.
     * REV2.0 introduced the sign bit to refer to input devices, breaking the cardinality of
     * one bit in the mask - one device.
     *
     * @param[in] devices mask of the device to check.
     *
     * @return true if input device, false otherwise.
     */
    static bool isAudioInputDevice(uint32_t devices);

    static const uint32_t USEC_TO_SEC = 1000000; /**< Constant used or delays computation */

private:
    static const uint32_t FRAME_ALIGNEMENT_ON_16 = 16; /**< 16 is an audioflinger requirement. */
};

}; // namespace android

