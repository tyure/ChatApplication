
Цей проект представляє собою чат-додаток, реалізований з використанням Qt. Додаток підтримує створення особистих і групових чатів, управління списком друзів, відправку та отримання повідомлень в реальному часі

Класи

1. MainWindow

Основне вікно програми, яке містить логіку управління чатами, списками друзів та іншими функціями.

Файли: mainwindow.cpp, mainwindow.h

Основні методи:
showRegistrationForm(): Відображає форму реєстрації користувача.
onRegistrationSuccessful(const QString &username): Обробляє успішну реєстрацію користувача.
onLoginSuccessful(const QString &username): Обробляє успішний вхід користувача.
openChat(): Відкриває вибраний чат.
createChat(): Створює новий чат.
createGroupChat(): Створює новий груповий чат.
deleteChat(): Видаляє вибраний чат.
openFriendList(): Відкриває список друзів.
loadChats(): Завантажує список чатів.
saveChats(): Зберігає список чатів.

2. ChatClient

Основний клас для управління чатами та друзями.

Файли: chatclient.cpp, chatclient.h

Основні методи:
setUser(const User &user): Встановлює поточного користувача.
getUser() const: Повертає поточного користувача.
createChat(const QString &friendName): Створює новий чат з другом.
createGroupChat(const QString &groupName, const QStringList &users, const QString &creator): Створює новий груповий чат.
sendMessage(const QString &roomName, const QString &content): Відправляє повідомлення в чат.
sendGroupChatMessage(const QString &roomName, const QString &content): Відправляє повідомлення в груповий чат.
deleteChat(const QString &roomName): Видаляє чат.
getChatRooms() const: Повертає список чатів.
saveChatRooms() const: Зберігає список чатів.
loadChatRooms(): Завантажує список чатів.
addFriend(const QString &friendName): Додає нового друга.
removeFriend(const QString &friendName): Видаляє друга.
getFriends() const: Повертає список друзів.
saveFriends(const QString &username) const: Зберігає список друзів.
loadFriends(const QString &username): Завантажує список друзів.
getRegisteredUsers() const: Повертає список зареєстрованих користувачів.
loadRegisteredUsers(): Завантажує список зареєстрованих користувачів.

3. ChatRoom

Клас для представлення кімнати чату, включаючи учасників та повідомлення.

Файли: chatroom.cpp, chatroom.h

Основні методи:
getName() const: Повертає назву кімнати чату.
getMessages() const: Повертає список повідомлень в кімнаті.
addMessage(const Message &message): Додає повідомлення в кімнату.
loadMessages(const QString &filename): Завантажує повідомлення з файлу.
saveMessages(const QString &filename) const: Зберігає повідомлення у файл.
addParticipant(const QString &participant): Додає учасника до кімнати.
getParticipants() const: Повертає список учасників кімнати.
operator==(const ChatRoom &other) const: Порівнює дві кімнати на рівність.

4. ChatWindow

Вікно GUI для конкретного чату.

Файли: chatwindow.cpp, chatwindow.h

Основні методи:
sendMessage(): Відправляє повідомлення.
receiveMessage(const Message &message): Отримує повідомлення.
loadChatHistory(): Завантажує історію чату.

5. GroupChatWindow

Вікно GUI для групового чату.

Файли: groupchatwindow.cpp, groupchatwindow.h

Основні методи:
sendMessage(): Відправляє повідомлення.
receiveMessage(const Message &message): Отримує повідомлення.
addUser(): Додає користувача до групового чату.
loadChatHistory(): Завантажує історію чату.

6. FriendListWindow

Вікно GUI для управління списком друзів.

Файли: friendlistwindow.cpp, friendlistwindow.h

Основні методи:
addFriend(): Додає нового друга.
removeFriend(): Видаляє друга.
loadFriends(): Завантажує список друзів.
saveFriends(): Зберігає список друзів.

7. GroupChatDialog

Діалогове вікно для створення групового чату.

Файли: groupchatdialog.cpp, groupchatdialog.h

Основні методи:
getSelectedUsers() const: Повертає список вибраних користувачів.
getGroupName() const: Повертає назву групи.
on_addUserButton_clicked(): Додає користувача до списку вибраних.
on_removeUserButton_clicked(): Видаляє користувача зі списку вибраних.
on_saveButton_clicked(): Зберігає створену групу.

8. RegisterForm

Форма для реєстрації та входу користувачів.

Файли: registerform.cpp, registerform.h

Основні методи:
onRegisterButtonClicked(): Обробляє натискання кнопки реєстрації.
onLoginButtonClicked(): Обробляє натискання кнопки входу.
isUserExists(const QString &username): Перевіряє, чи існує користувач.

9. User

Клас для представлення користувача з ім'ям.

Файли: user.cpp, user.h

Основні методи:
getUsername() const: Повертає ім'я користувача.

10. Message

Клас для представлення повідомлення.

Файли: message.cpp, message.h

Основні методи:
getSender() const: Повертає відправника повідомлення.
getContent() const: Повертає вміст повідомлення.
getTimestamp() const: Повертає час відправлення повідомлення.
getChatRoomName() const: Повертає назву кімнати чату, до якої належить повідомлення.

Відповідність вимогам лабораторної роботи №2

Проект чат-додатка на Qt реалізує більшість вимог, описаних у лабораторній роботі №2, включаючи принципи ООП, використання патернів проектування (Singleton, Facade, Observer), реалізацію графічного інтерфейсу користувача з використанням Qt, а також збереження даних у файловій системі.
