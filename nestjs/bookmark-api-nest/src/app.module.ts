import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { MongooseModule } from '@nestjs/mongoose';
import { BookmarkModule } from './modules/bookmarks/bootkmark.module';

@Module({
  imports: [
    MongooseModule.forRoot(
      process.env.MONGODB_CONNECTION_STRING ||
        'mongodb://localhost/bookmarkAmir',
    ),
    BookmarkModule,
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
