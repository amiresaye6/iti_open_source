import { Bookmark } from '../schemas/bookmark.schema';

export interface BookmarkResponse {
  message: string;
  data: Bookmark[];
  pagination: {
    limit: number;
    currentPage: number;
    pages: number;
    total: number;
  };
}
