#include "post.h"
#include "config.h"
#include "WiFi.h"
#include "ArduinoHttpClient.h"
#include "secrets.h"
#include "com.h"


namespace post {
    bool willPost = false;
    WiFiClient wifi;
    HttpClient client = HttpClient(wifi, SERVER_ADDRESS, SERVER_PORT);

    void begin() {
        //TODO add athorization headers if needed
    }

    void setPost() {
        willPost = true;
    }

    void update() {
        if (willPost) {
            postNow("{}");
        }
        willPost = false;
    }

    void postNow(String postData) {
        client.post(URL_PATH, "application/json", postData);

    }
}