#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStubSuccess(float celcius) {
    printf("ALERT SUCCESS: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int networkAlertStubFailed(float celcius) {
    printf("ALERT FAILED: Temperature is %.1f celcius.\n", celcius);
    return 500;
}

void alertInCelcius(float farenheit, int (*alertTransmitter)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = alertTransmitter(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5, networkAlertStubSuccess);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, networkAlertStubFailed);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
