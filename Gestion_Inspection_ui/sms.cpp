#include "sms.h"
#include <QtNetwork>


SMS::SMS()
{

}
void SMS::sendSMS(const QString &to, const QString &message) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/ACe5f356d6a4efad791ff0d977af95820d/Messages.json"); // lien site de l api _servie message ( twilio )
    QNetworkRequest request(url);


    QString credentials = "ACe5f356d6a4efad791ff0d977af95820d:99c616ade6f43cb699bf46a11942bf42";    // partie 1 = SID partie 2 = token
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);

    QString twilio_phone_number = "+12565677501"; //numero from where you get the sms
    QByteArray postData;
    postData.append("From="+twilio_phone_number);  // from wherre i get the sms
    postData.append("&To=" + to); // to who i send the sms
    postData.append("&Body=" + message); // sms message



}
