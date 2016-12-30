#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("pesetacoin://LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("pesetacoin:LGfR55WPULK6S7eoeEGYW5CLSUFWWZiH5Q?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
