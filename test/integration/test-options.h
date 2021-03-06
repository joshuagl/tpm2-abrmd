/*
 * Copyright (c) 2017 - 2018, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TEST_OPTIONS_H
#define TEST_OPTIONS_H

#include <gio/gio.h>
#include "tss2-tcti-tabrmd.h"

/* Default number of attempts to init selected TCTI */
#define TCTI_RETRIES_DEFAULT 5

/* environment variables holding TCTI config */
#define ENV_TCTI      "TABRMD_TEST_TCTI"
#define ENV_TCTI_CONF "TABRMD_TEST_TCTI_CONF"
#define ENV_TCTI_RETRIES    "TABRMD_TEST_TCTI_RETRIES"

#define TEST_OPTS_DEFAULT_INIT { \
    .tcti_filename = NULL, \
    .tcti_conf = NULL, \
    .tcti_retries = TCTI_RETRIES_DEFAULT, \
}

typedef struct {
    const char *tcti_filename;
    const char *tcti_conf;
    uintmax_t   tcti_retries;
} test_opts_t;

/* functions to get test options from the user and to print helpful stuff */

const char  *bus_str_from_type          (GBusType              bus_type);
GBusType     bus_type_from_str          (const char*           bus_type_str);
int          get_test_opts_from_env     (test_opts_t          *opts);
int          sanity_check_test_opts     (test_opts_t          *opts);
void         dump_test_opts             (test_opts_t          *opts);

#endif /* TEST_OPTIONS_H */
