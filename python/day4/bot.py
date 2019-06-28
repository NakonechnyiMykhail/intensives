import telebot

from telebot import types

token = ''

bot = telebot.TeleBot(token)


def get_closest_bank(location):
    lat = location.latitude
    lon = location.longitude
    bank_address = 'Сумская, 20'
    bank_lat, bank_lon = 49.99647645, 36.23345579
    return bank_address, bank_lat, bank_lon


@bot.message_handler(content_types=['location'])
def handle_location(message):
    location = message.location
    bank_address, bank_lat, bank_lon = get_closest_bank(location)
    # logo = open('bank.jpg', 'rb')
    bot.send_photo(message.chat.id, logo, caption='Ближайший банк находится по адресу {}'.format(bank_address))
    bot.send_location(message.chat.id, bank_lat, bank_lon)



@bot.message_handler(content_types=['location'])
def handler_location(message):
    print(message.location)
    bot.send_message(message.chat.id, text='Ближайший банк')



# # sendVideo
# video = open('/tmp/video.mp4', 'rb')
# bot.send_video(chat_id, video)
# bot.send_video(chat_id, "FILEID")
#
# # sendVideoNote
# videonote = open('/tmp/videonote.mp4', 'rb')
# bot.send_video(chat_id, videonote)
# bot.send_video(chat_id, "FILEID")
#
# # sendLocation
# bot.send_location(chat_id, lat, lon)


# Начало
bot = telebot.TeleBot(token)
currencies = ['евро', 'доллар', 'фунты']


def create_keyboard():
    keyboard = types.InlineKeyboardMarkup(row_width=2)
    buttons = [types.InlineKeyboardButton(text=c, callback_data=c)
               for c in currencies]
    keyboard.add(*buttons)
    return keyboard


@bot.callback_query_handler(func=lambda x: True)
def callback_handler(callback_query):
    message = callback_query.message
    text = callback_query.data
    currency, value = check_currency_value(text)
    if currency:
        bot.answer_callback_query(callback_query.id, text='Курс {} равен {}'.format(currency, value))
    else:
        bot.send_message(message.chat.id, text='Укажите валюту')


def currency_in_message(message):
    for currency in currencies:
        if currency in message.text.lower():
            return True
    return False


def check_currency_value(text):
    currency_values = {'евро': 30, 'доллар': 25, 'фунты':35}
    for currency, value in currency_values.items():
        if currency in text.lower():
            return currency, value
    return None, None


@bot.message_handler(commands=['rate'])
@bot.message_handler(func=currency_in_message)
def handle_message(message):
    currency, value = check_currency_value(message.text)
    keyboard = create_keyboard()
    if currency:

        bot.send_message(message.chat.id, text='Курс {} равен {}'.format(currency, value),
                         reply_markup=keyboard)
    else:
        bot.send_message(message.chat.id, text='Укажите валюту', reply_markup=keyboard)


@bot.message_handler()
def handle_message(message):
    print(message)
    bot.send_message(message.chat.id, text='Это бот для проверки курса валют.')


bot.polling()




def create_markup(currencies):
    keyboard = types.InlineKeyboardMarkup(row_width=2)
    buttons = [types.InlineKeyboardButton(text=currency, callback_data=currency)
               for currency in currencies]
    keyboard.add(*buttons)
    return keyboard

@bot.callback_query_handler(func=lambda x: True)
def handle_currency_callback(callback_query):
    message = callback_query.message
    data = callback_query.data
    currency, rate = check_currency_value(data)
    if currency:
        bot.answer_callback_query(callback_query_id=callback_query.id,
                                 text='Курс {} равен {}'.format(currency, rate))