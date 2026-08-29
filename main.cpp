#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// هيكل التطبيق داخل متجر BudgieOS
struct App {
    string name;
    string category;
    bool isInstalled;
};

// نواة ونظام BudgieOS المصغر
class BudgieOS {
private:
    string osName;
    string version;
    vector<App> storeApps;
    stack<string> actionHistory;
    bool isRunning;

public:
    BudgieOS(string name, string ver) {
        osName = name;
        version = ver;
        isRunning = true;
        
        // تطبيقات أساسية في نظام BudgieOS
        storeApps = {
            {"Budgie Browser", "Internet", false},
            {"Budgie Player", "Media", false},
            {"CodePad", "Development", false},
            {"Calculator", "Utilities", true}
        };
    }

    void bootSequence() {
        cout << "========================================\n";
        cout << "  Starting " << osName << " v" << version << " ...\n";
        cout << "  Initializing C++ Kernel & Drivers...\n";
        cout << "  System Ready!\n";
        cout << "========================================\n";
    }

    void showDesktop() {
        cout << "\n--- سطح مكتب " << osName << " ---\n";
        cout << "1. فتح متجر التطبيقات (Budgie Store)\n";
        cout << "2. استعراض التطبيقات المثبتة\n";
        cout << "3. معلومات النظام (System Info)\n";
        cout << "4. إيقاف تشغيل النظام (Shutdown)\n";
        cout << "اختر عملية: ";
    }

    void openStore() {
        int choice;
        string input;
        do {
            cout << "\n=== متجر تطبيقات " << osName << " ===\n";
            cout << "1. عرض كل التطبيقات\n";
            cout << "2. بحث عن تطبيق\n";
            cout << "3. تثبيت تطبيق\n";
            cout << "4. إلغاء تثبيت آخر تطبيق (Undo)\n";
            cout << "5. العودة لسطح المكتب\n";
            cout << "اختر: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    listApps();
                    break;
                case 2:
                    cout << "أدخل كلمة البحث: ";
                    cin >> ws;
                    getline(cin, input);
                    searchApp(input);
                    break;
                case 3:
                    cout << "أدخل اسم التطبيق المراد تثبيته: ";
                    cin >> ws;
                    getline(cin, input);
                    installApp(input);
                    break;
                case 4:
                    undoAction();
                    break;
                case 5:
                    cout << "العودة...\n";
                    break;
                default:
                    cout << "خيار غير صحيح.\n";
            }
        } while (choice != 5);
    }

    void listApps() {
        cout << "\n[قائمة التطبيقات المتاحة]:\n";
        for (size_t i = 0; i < storeApps.size(); ++i) {
            cout << i + 1 << ". " << storeApps[i].name << " (" << storeApps[i].category << ") - " 
                 << (storeApps[i].isInstalled ? "[مثبت]" : "[غير مثبت]") << "\n";
        }
    }

    void searchApp(string query) {
        cout << "\n--- نتائج البحث عن: \"" << query << "\" ---\n";
        bool found = false;
        string qLower = query;
        transform(qLower.begin(), qLower.end(), qLower.begin(), ::tolower);

        for (auto& app : storeApps) {
            string nameLower = app.name;
            transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);

            if (nameLower.find(qLower) != string::npos) {
                cout << "• " << app.name << " [" << app.category << "] " 
                     << (app.isInstalled ? "جاهز للاستخدام" : "متاح للتحميل") << "\n";
                found = true;
            }
        }
        if (!found) cout << "لم يتم العثور على نتائج.\n";
    }

    void installApp(string appName) {
        for (auto& app : storeApps) {
            string aNameLower = app.name;
            string targetLower = appName;
            transform(aNameLower.begin(), aNameLower.end(), aNameLower.begin(), ::tolower);
            transform(targetLower.begin(), targetLower.end(), targetLower.begin(), ::tolower);

            if (aNameLower == targetLower) {
                if (!app.isInstalled) {
                    app.isInstalled = true;
                    actionHistory.push(app.name);
                    cout << "[نجاح] تم تثبيت " << app.name << " في " << osName << "!\n";
                } else {
                    cout << "[تنبيه] التطبيق مثبت مسبقاً.\n";
                }
                return;
            }
        }
        cout << "[خطأ] التطبيق غير موجود في المتجر.\n";
    }

    void undoAction() {
        if (!actionHistory.empty()) {
            string last = actionHistory.top();
            actionHistory.pop();
            for (auto& app : storeApps) {
                if (app.name == last) {
                    app.isInstalled = false;
                    cout << "[تراجع] تم إزالة تثبيت: " << last << "\n";
                    return;
                }
            }
        } else {
            cout << "[تنبيه] لا توجد عمليات سابقة للتراجع عنها.\n";
        }
    }

    void showInstalledApps() {
        cout << "\n[التبيقات المثبتة حالياً]:\n";
        bool any = false;
        for (auto& app : storeApps) {
            if (app.isInstalled) {
                cout << " - " << app.name << "\n";
                any = true;
            }
        }
        if (!any) cout << "لا توجد تطبيقات مثبتة.\n";
    }

    void systemInfo() {
        cout << "\n--- معلومات النظام ---\n";
        cout << "OS Name: " << osName << "\n";
        cout << "Version: " << version << "\n";
        cout << "Architecture: C++ Simulated Kernel\n";
    }

    void shutdown() {
        cout << "Shutting down " << osName << "...\n";
        isRunning = false;
    }

    bool getStatus() { return isRunning; }
};

int main() {
    BudgieOS myOS("BudgieOS", "0.3");
    myOS.bootSequence();

    int choice;
    while (myOS.getStatus()) {
        myOS.showDesktop();
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                myOS.openStore();
                break;
            case 2:
                myOS.showInstalledApps();
                break;
            case 3:
                myOS.systemInfo();
                break;
            case 4:
                myOS.shutdown();
                break;
            default:
                cout << "خيار خاطئ، حاول مرة أخرى.\n";
        }
    }

    return 0;
}

