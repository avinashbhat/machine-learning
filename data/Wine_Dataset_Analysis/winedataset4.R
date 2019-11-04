#clear console,plots,datasets
rm(list=ls())
cat("\014")
graphics.off()

#set the working directory and load libraries
setwd("/home/avinash/Desktop/wineproject/Wine_Dataset_Analysis")
library(rpart)
library(rpart.plot)
library(caret)

#load the data sets into variables
white<-read.csv(file = "winequality-white.csv",head=TRUE, sep=";")
red<-read.csv(file = "winequality-red.csv",head=TRUE, sep=";")

#add data field 'category'
white$cat<-"white"
red$cat<-"red"

#combine the data to another variable
newdata<-rbind(red,white)
head(newdata)
summary(newdata)

#splitting to trining and test ca
k<-sample(x = 2, size = nrow(newdata), replace = TRUE, prob = c(0.1,0.9))
test.cases<-newdata[k==2,]
training.cases<-newdata[k==1,]
table(newdata$cat)/nrow(newdata)

#classification using rpart and prediction
fitcTree<-rpart(data = training.cases,method = "class", formula =  cat~fixed.acidity+volatile.acidity+citric.acid+total.sulfur.dioxide+chlorides+alcohol+density)
predcTree<-predict(fitcTree,newdata=test.cases,type="class")
rpart.plot(fitcTree)

#regression using rpart and prediction
fitqTree<-rpart(data = training.cases,method = "anova", formula =  quality~fixed.acidity+volatile.acidity+citric.acid+total.sulfur.dioxide+chlorides+alcohol+density)
predrTree<-predict(fitqTree,newdata=test.cases,type="vector")
rpart.plot(fitqTree)

#representation of testing with a subset
temp<-test.cases[300,]
print(temp)
predict(object = fitcTree,newdata = temp,type = "class")

#confusion matrix
confusionMatrix(predcTree,test.cases$cat)

