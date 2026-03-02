import { Module } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { Bookmark, BookmarkSchema } from './schemas/bookmark.schema';
import { BookmarkService } from './bookmark.service';
import { BookmarkController } from './bookmark.controller';

@Module({
  imports: [
    MongooseModule.forFeature([
      { name: Bookmark.name, schema: BookmarkSchema },
    ]),
  ],
  controllers: [BookmarkController],
  providers: [BookmarkService],
})
export class BookmarkModule {}
