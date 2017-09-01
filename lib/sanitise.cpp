//;(c)kuiash.com 2015+;code@kuiash.com;mere cottage,linnetts lane,sturmer,essex,cb9 7xw;reg 08590405;vat 196184766

#include <QProcess>

QString sanitise(const QString & criminally_insane)
{
    int spaces = 0;
    QString partially_sane, sane;

    QProcess decode;
    decode.start("c++filt -n " + criminally_insane);
    if (decode.waitForFinished(1000)) {
        partially_sane = QString::fromLatin1(decode.readAll());

        foreach(QChar issue, partially_sane) {
            if (issue == '<') {
                sane += "<\n";
                spaces += 4;
                sane += QString(spaces, ' ');
            } else if (issue == '>') {
                spaces -= 4;
                sane += "\n" + QString(spaces, ' ') + ">";
            } else if (issue == ',') {
                sane += ",\n" + QString(spaces, ' ');
            } else if (issue != ' '){
                sane += issue;
            }
        }
    } else {
        return "???FAILURE";
    }
    return sane;
}
